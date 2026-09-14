#ifndef _GLIBCXX_THREAD_
#define _GLIBCXX_THREAD_

//#include <ratio>
namespace std {
	class mutex {
		public:
            void lock();
		    void unlock();
    };
	
	class thread {
		
	};
	
	namespace this_thread {
		inline void sleep_for(const chrono::duration<long double, ratio<3600, 1>>& __rtime)
                { }
	};
};

#endif /* _GLIBCXX_THREAD_ */