///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
/// @file	rc_smartptr.h
///	\brief 	ustom string class APIs
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_smartptr_h
#define rc_smartptr_h

namespace rendercore_engine
{
    /// <summary>
    /// Smart pointer to manage objects in scripts
    /// Two use cases are handled
    /// 1. New object : here the object life to managed with a instance counter
    ///    These are object that is created within script with new operator. And it shall be deleted
    ///    when it is no longer necessary
    /// 2. pointer assignment : Here the object life is not to be managed as it will be just holding it for some operation
    ///    i.e. the object shall not be deleted by rdf_smartptr, as its owned by the engine
    /// </summary>
    /// <typeparam name="T"></typeparam>
    template <class T>
    class rdf_smartptr
    {
    private:
        /// 'true' indicates that it a weak pointer reference, meaning it shall not be managed or deleted.
        /// 'false' indicates that the pointer is created in the script and to be managed and finally deleted
        bool weakPtr = false;
        T* ptr = nullptr;           ///< Pointer to the object
        size_t* counter = nullptr;  ///< Reference counter to be used to manage object if weakPtr = false
        /// <summary>
        /// decrements the reference count by one
        /// try to delete the 'ptr' if its managed and not used anymore
        /// </summary>
        inline void try_delete()
        {
            if (counter != nullptr)
            {
                if ((*counter) > 0U)
                {
                    (*counter)--;
                }
                if ((*counter) == 0U)
                {
                    delete counter;
                    counter = nullptr;
                    if (ptr != nullptr)
                    {
                        if (!weakPtr)
                        {
                            delete ptr;
                        }
                        ptr = nullptr;
                    }
                    weakPtr = false;
                }
            }
            else
            {
                ptr = nullptr;
                weakPtr = false;
            }
        }
        /// <summary>
        /// Swaps the current pointer and counters with that of another
        /// Can be invoked due to a copy construct or assignment
        /// </summary>
        /// <param name="p_rptr">New pointer to be managed by this class</param>
        /// <param name="p_rcounter">Reference to Counter if the assignment came from another rdf_smartptr, else it will be null</param>
        /// <param name="p_isweak">indicates its a weak pointer or not</param>
        inline void swap(T* const p_rptr, size_t* const p_rcounter, const bool p_isweak)
        {
            if (p_rptr != ptr)
            {
                // try to delete existing one if this is the last instance
                try_delete();
                ptr = p_rptr;
                weakPtr = p_isweak;
                if ((p_rptr != nullptr) && (!weakPtr))
                {
                    counter = p_rcounter;
                    if (p_rcounter == nullptr)
                    {
                        try 
                        {
                            counter = new size_t;
                            (*counter) = 1U;
                        }
                        catch (const std::bad_alloc& err) 
                        {
                            RcDebugErrorLogId(rc_error_logId::elSmartPtrAllocFailed);
                            if (err.what() != nullptr)
                            {
                                WLOG("smartptr exception %s\n", err.what());
                            }
                        }
                    }
                    else
                    {
                        (*counter)++;
                    }
                }
                else
                {
                    counter = nullptr;
                }
            }
        }
        /// <summary>
        /// Swaps the passed smart pointer over current one held by this
        /// </summary>
        /// <param name="p_rhs"></param>
        inline void swap(const rdf_smartptr& p_rhs)
        {
            if (const_cast<rdf_smartptr&>(p_rhs).GetPointer() != ptr)
            {
                swap(const_cast<rdf_smartptr&>(p_rhs).GetPointer(), const_cast<rdf_smartptr&>(p_rhs).GetCounter(), const_cast<rdf_smartptr&>(p_rhs).IsWeak());
            }
        }
    public:
        /// Construct an empty smart pointer
        inline rdf_smartptr()
        {
        }
        /// Constructor from a object pointer
        /// p_weak = true  : assume this to be a stack object and not to be managed
        /// p_weak = false : assume this to be a heap object and to be managed
        inline rdf_smartptr(T* const p_ptr, const bool p_weak = true)
        {
            swap(p_ptr, nullptr, p_weak);
        }
        /// copy construct from another smart pointer
        inline rdf_smartptr(const rdf_smartptr<T>& p_sp)
        {
            swap(p_sp);
        }
        /// copy construct from another smart pointer
        inline rdf_smartptr(const rdf_smartptr<T>&& p_sp)
        {
            swap(p_sp);
        }
        /// Destructor 
        /// Tries to delete the managed object if no one else is using it
        inline ~rdf_smartptr()
        {
            try_delete();
        }
        /// Overloading dereferncing operator 
        inline T& operator*()
        {
            if (ptr == nullptr)
            {
                RcDebugErrorLogId(rc_error_logId::elSmartPtrScriptDeferNull);
                throw std::runtime_error("dereferncing nullpointer");
            }
            return *ptr;
        }
        /// Overloading arrow operator so that members of T can be accessed 
        /// like a pointer (useful if T represents a class or struct or union type) 
        inline T* operator->() const
        {
            if (ptr == nullptr)
            {
                RcDebugErrorLogId(rc_error_logId::elSmartPtrArrowOpScriptDeferNull);
                throw std::runtime_error("dereferncing nullpointer");
            }
            return ptr;
        }
        /// Overloading assignment : assign another smart pointer
        inline rdf_smartptr& operator=(rdf_smartptr& p_rhs) noexcept
        {
            swap(p_rhs);
            return *this;
        }
        /// Overloading assignment : assign another smart pointer
        inline rdf_smartptr& operator=(const rdf_smartptr&& p_rhs) noexcept
        {
            swap(p_rhs);
            return *this;
        }
        /// Overloading assignment : assign object pointer
        /// Here its assumed that object to be not managed. i.e. creates a weak smart popinter
        inline rdf_smartptr& operator=(T* const p_rhs)
        {
            swap(p_rhs, nullptr, true);
            return(*this);
        }
        inline operator T* () const
        {
            return ptr;
        }
        inline bool operator == (const rdf_smartptr& p_rhs) const
        {
            bool fl_sts;
            if (ptr == const_cast<rdf_smartptr&>(p_rhs).GetPointer())
            {
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline bool operator == (const T* const p_rhs) const
        {
            bool fl_sts;
            if (ptr == p_rhs)
            {
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline T* GetPointer() const
        {
            return(ptr);
        }
        inline bool IsWeak() const
        {
            return(weakPtr);
        }
        inline size_t* GetCounter() const
        {
            return(counter);
        }
    };
    /// giving a convinient name for text node
    using Texture2D = rdf_smartptr<gfx3dTexture2D>;
    using Texture = rdf_smartptr<gfx3dTexture2D>;
    using Cubemap = rdf_smartptr<gfx3dTexture2D>;
    using Material = rdf_smartptr<gfx3dMaterial>;
    using Camera = rdf_smartptr<gfx3dCamera>;
    using Transform = rdf_smartptr<gfx3dTransform>;
    using RCText = rdf_smartptr<gfx3dTextMeshPro>;
    using RCLight = rdf_smartptr<gfx3d_scg_light>;
    using TextMeshPro = rdf_smartptr<gfx3dTextMeshPro>;
    using Mesh = rdf_smartptr<gfx3d_scg_mesh>;
    using VideoPlayer = rdf_smartptr<gfxVideoPlayer>;
    using RCLine2D = rdf_smartptr<rc_2dline>;
    using Node3D = rdf_smartptr<gfx3d_scg_node>;
    namespace RenderCore
    {
        using RCText = rdf_smartptr<gfx3dTextMeshPro>;
    }
    using RCSManager = rdf_smartptr<RCState_Manager>;
    using AsyncOperation = rc_sceneload_sts;
    template<class T>
    using List = rdf_smartptr<std::vector<T>>;
    template<class T, class V>
    using Dictionary = rdf_smartptr<std::map<T, V>>;
    template<class T, class V>
    using KeyValuePair = std::pair<T, V>;
    /// <summary>
    /// Returns the index of the passed item in the List
    /// </summary>
    /// <typeparam name="T">Type of entries in list</typeparam>
    /// <param name="p_list">List</param>
    /// <param name="p_item">Item to be searched</param>
    /// <returns> >=0 Index of the item in list. -1 if item not in List</returns>
    template<class T>
    inline int32_t ListIndexOf(List<T>& p_list, T& p_item)
    {
        int32_t fl_index = -1;
        if (p_list != nullptr)
        {
            auto fl_it = std::find(p_list->begin(), p_list->end(), p_item);
            if (fl_it != p_list->end())
            {
                fl_index = static_cast<int32_t>(std::distance(p_list->begin(), fl_it));
            }
        }
        return(fl_index);
    }
    /// <summary>
    /// Returns the index of the passed item in the List
    /// </summary>
    /// <typeparam name="T">Type of entries in list</typeparam>
    /// <param name="p_list">List</param>
    /// <param name="p_item">Item to be searched</param>
    /// <returns> >=0 Index of the item in list. -1 if item not in List</returns>
    template<class T>
    inline int32_t ListIndexOf(List<T>& p_list, const T&& p_item)
    {
        int32_t fl_index = -1;
        if (p_list != nullptr)
        {
            auto fl_it = std::find(p_list->begin(), p_list->end(), p_item);
            if (fl_it != p_list->end())
            {
                fl_index = static_cast<int32_t>(std::distance(p_list->begin(), fl_it));
            }
        }
        return(fl_index);
    }
    /// <summary>
    /// Inserts an item to list
    /// </summary>
    /// <typeparam name="T">Type of entries in list</typeparam>
    /// <param name="p_list">List to which item to be added</param>
    /// <param name="p_index">index at which item to be added</param>
    /// <param name="p_item">item to be added</param>
    template<class T>
    inline void ListInsert(List<T>& p_list, int32_t p_index, T& p_item)
    {
        if (p_list != nullptr)
        {
            if ((p_index >= 0) && (p_index < p_list->size()))
            {
                p_list->insert(p_list->begin() + p_index, p_item);
            }
        }
    }
    /// <summary>
    /// Inserts an item to list
    /// </summary>
    /// <typeparam name="T">Type of entries in list</typeparam>
    /// <param name="p_list">List to which item to be added</param>
    /// <param name="p_index">index at which item to be added</param>
    /// <param name="p_item">item to be added</param>
    template<class T>
    inline void ListInsert(List<T>& p_list, int32_t p_index, T&& p_item)
    {
        if (p_list != nullptr)
        {
            if ((p_index >= 0) && (p_index < p_list->size()))
            {
                p_list->insert(p_list->begin() + p_index, p_item);
            }
        }
    }
    /// <summary>
    /// Removes an item from specified index if the valid
    /// </summary>
    /// <typeparam name="T">Type of elements in list</typeparam>
    /// <param name="p_list">List object</param>
    /// <param name="p_index">index to be removed</param>
    template<class T>
    inline void ListRemoveAt(List<T>& p_list, int32_t p_index)
    {
        if (p_list != nullptr)
        {
            if ((p_index >= 0) && (p_index < p_list->size()))
            {
                p_list->erase(p_list->begin() + p_index);
            }
        }
    }
    /// <summary>
    /// Removes the specified item, if present in list
    /// </summary>
    /// <typeparam name="T">Type of elements in list</typeparam>
    /// <param name="p_list">List object</param>
    /// <param name="p_item">item to be removed</param>
    template<class T>
    inline void ListRemove(List<T>& p_list, T& p_item)
    {
        int32_t fl_index = ListIndexOf(p_list, p_item);
        ListRemoveAt(p_list, fl_index);
    }
    /// <summary>
    /// Removes the specified item, if present in list
    /// </summary>
    /// <typeparam name="T">Type of elements in list</typeparam>
    /// <param name="p_list">List object</param>
    /// <param name="p_item">item to be removed</param>
    template<class T>
    inline void ListRemove(List<T>& p_list, T&& p_item)
    {
        int32_t fl_index = ListIndexOf(p_list, p_item);
        ListRemoveAt(p_list, fl_index);
    }
    /// <summary>
    /// Remove specified number 'p_count' items starting at index 'p_index' from List 'p_list'
    /// </summary>
    /// <typeparam name="T">Type of elements in list</typeparam>
    /// <param name="p_list">List object</param>
    /// <param name="p_index">index of item where the remove must start</param>
    /// <param name="p_count">number of items to be removed</param>
    template<class T>
    inline void ListRemoveRange(List<T>& p_list, const int32_t p_index, int32_t p_count)
    {
        if ((p_list != nullptr) && (p_index >= 0))
        {
            while ((p_count > 0) && (p_index < p_list->size()))
            {
                p_count--;
                ListRemoveAt(p_list, p_index);
            }
        }
    }
}
#endif
