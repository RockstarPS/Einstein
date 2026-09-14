#ifndef DK_RUNTIME_VERSION
#define DK_RUNTIME_VERSION

namespace dk {
namespace runtime {
namespace core {
	class test {
		public:
			test() {}
			static void dummy (void){
			}
	};
};
};
};

namespace std {
	class mutex {
		public:
            void lock();
		    void unlock();
    };
	
	class thread {
		public:
			typedef unsigned long int native_handle_type;
			
			template<typename _Callable, typename... _Args>
			explicit thread(_Callable&& __f, _Args&&... __args)
			{ }
	  
			void join();
			native_handle_type native_handle() {}
	};
	
	namespace this_thread {
		inline void sleep_for(const chrono::duration<long double, ratio<3600, 1>>& __rtime)
                { }
	};
};

#endif //DK_RUNTIME_VERSION
