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
//  Filename    : gfx3d_scg_memory_monitor.h
//  Description : Memory Monitor for screen objects
//  Created on  : 09-Mar-2019 by csakthiv@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_scg_memory_monitor_h
#define gfx3d_scg_memory_monitor_h
#include <set>

namespace rendercore_engine
{
	class gfx3d_scg_display;
	/// <summary>
	/// state of adding an object to memory monitor
	/// </summary>
	enum class rc_MOAddStatus
	{
		aoFail,				///< Add object failed
		aoSucceed,			///< Object is newly added
		aoAlreadyPresent    ///< Object was already in list
	};

	class gfx3d_scg_mem_obj
	{
	protected:
		uint64_t frameCounter;							///< It hold the current frame counter value.
		uint32_t gpuSize;								///< Size of GPU memory used by the object.
		uint32_t heapSize;								///< Size of HEAP memory used by the object.
		gfx3d_scg_mem_obj& operator=(const gfx3d_scg_mem_obj& p_src);
		/// <summary>
		/// Set function for setting the size of GPU memory used for a memory object.
		/// </summary>
		/// <param name="p_size"></param>
		void SetGpuSize(const uint32_t p_size);
		/// <summary>
		/// Set function for setting the size of Heap memory used for a memory object.
		/// </summary>
		/// <param name="p_size"></param>
		void SetHeapSize(const uint32_t p_size);
	public:
		 /// <summary>
		 /// Consturctor for class gfx3d_scg_mem_obj.
		 /// </summary>
		 /// <param name=""></param>
		 gfx3d_scg_mem_obj(void);
		 /// <summary>
		 /// Parametarized Constructor for class gfx3d_scg_mem_obj.
		 /// </summary>
		 /// <param name="p_frameCounter"></param>
		 /// <param name="p_gpuSize"></param>
		 /// <param name="p_heapSize"></param>
		 gfx3d_scg_mem_obj(const uint64_t p_frameCounter, const uint32_t p_gpuSize, const uint32_t p_heapSize);
		 /// <summary>
		 /// Copy constructor for class gfx3d_scg_mem_obj
		 /// </summary>
		 /// <param name="p_src"></param>
		 /// <returns></returns>
		 gfx3d_scg_mem_obj(const gfx3d_scg_mem_obj& p_obj);
		 ///<summary>
		 /// Destructor for the class gfx3d_scg_mem_obj.
		 /// </summary>
		~gfx3d_scg_mem_obj(void);
		/// <summary>
		/// Set function FrameCounter.
		/// </summary>
		/// <param name="p_frameCounter"></param>
		void SetFrameCounter(const gfx3d_scg_display* const p_disp);
		/// <summary>
		/// Get function for frame counter member.
		/// </summary>
		/// <param name=""></param>
		/// <returns>value of frameCounter</returns>
		uint64_t GetFrameCounter(void) const;
		/// <summary>
		/// Get Function for getting the Gpu Size of memory object.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		uint32_t GetGpuSize(void) const;
		/// <summary>
		/// Get Function for getting the Heap Size of memory object.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		uint32_t GetHeapSize(void) const;
		/// <summary>
		/// Memory Object unload function.
		/// </summary>
		/// <param name=""></param>
		/// <returns>true if memory object is unloaded</returns>
		virtual bool MemMonitorObjUnload(void)=0;
		friend class gfx3d_scg_memory_monitor;

	};

	class gfx3d_scg_memory_monitor
	{
	private:
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
		mutable std::recursive_mutex data_mutex; ///< to prevent concurrent access to change data
#endif
		void UnloadAndRemoveMemObject(gfx3d_scg_mem_obj* const p_memmgr_obj);
		bool IsMemoryInLimits();						///< returns true if CPU and GPU memories are below threshold values
		bool IsGPUMemAvailable(size_t p_gpuMemRequested);
		bool IsHeapMemAvailable(size_t p_heapMemRequested);

	protected:
		gfx3d_scg_display* display = nullptr; ///<  display object
		std::set<gfx3d_scg_mem_obj*> active_memory_objs_list;   ///< Active memory Objects list.
		size_t gpu_memory_consumed;						///< The variable to hold the size of GPU memory consumed information.
		size_t heap_memory_consumed;					///< The variable to hold the size of Heap memory consumed information.
		size_t gpu_memory_threshold;					///< The variable to hold the threshold set for the GPU memory.
		size_t heap_memory_threshold;					///< The variable to hold the threshold set for the Heap memory.
		bool mem_monitor;								///< The variable to hold the RenderCore Memory Monitor to be used or not information.
	public:
		/// <summary>
		/// Constructor for a gfx3d_scg_memory_monitor class
		/// </summary>
		/// <param name="p_disp"></param>
		gfx3d_scg_memory_monitor(gfx3d_scg_display* const p_disp);

		/// Destructor for a gfx3d_scg_memory_monitor class
		///	</summary>
		~gfx3d_scg_memory_monitor(void);
		/// <summary>
		/// Get function for getting the Threshold set for the GPU memory.
		/// </summary>
		/// <returns> GPU memory Threshold.</returns>
		size_t GetGpuThreshold() const; 
		/// <summary>
		/// Get function for getting the Threshold set for the Heap Memory.
		/// </summary>
		/// <returns>Heap Memory Threshold</returns>
		size_t GetHeapThreshold() const;
		/// <summary>
		/// Get function for getting GPU memory consumed so far.
		/// </summary>
		/// <returns>Consumed GPU memory size</returns>
		size_t GetGpuUsage(void) const;
		/// <summary>
		/// Get function for getting the Heap memory consumed so far.
		/// </summary>
		/// <returns> Size of the Heap consumed.</returns>
		size_t GetHeapUsage(void) const;
		/// <summary>
		/// Set function setting the GPU memory threshold.
		/// </summary>
		/// <param name="p_gpu_memory_threshold"></param>
		void SetGpuThreshold(const size_t p_gpu_memory_threshold);
		/// <summary>
		/// Set function for setting the heap memory threshold.
		/// </summary>
		/// <param name="p_heap_memory_threshold"></param>
		void SetHeapThreshold(const size_t p_heap_memory_threshold);
		/// <summary>
		/// Set function for utilizing this meomory monitor.
		/// Set True if this memory monitor is needed.
		/// </summary>
		/// <param name="p_mem_monitor"></param>
		void SetActive(const bool p_mem_monitor);
		/// <summary>
		/// Get function for RenderCore Memory monitor has to be used.
		/// TRUE means, the application uses the RenderCore Memory monitor.
		/// </summary>
		/// <param name=""></param>
		/// <returns>True or false </returns>
		bool IsActive(void) const;										
		/// <summary>
		/// Adds the memory object into the queue.
		/// </summary>
		/// <param name="p_memmgr_obj"></param>
		/// <returns>True or false </returns>
		rc_MOAddStatus AddObject(gfx3d_scg_mem_obj* const p_memmgr_obj, const uint32_t p_gpu_size, const uint32_t p_heap_size);
		/// <summary>
		/// Removes the memory object from the queue.
		/// </summary>
		/// <param name="p_memmgr_obj"></param>
		void RemoveObject(gfx3d_scg_mem_obj* const p_memmgr_obj);
		/// <summary>
		/// This function is to release the object which is not active and it will be invoked from this module only.
		/// </summary>
		/// <param name=""></param>
		void TryRelease(void);

	};
}
#endif

