#ifndef SRC_DKOSALTHREAD_H_
#define SRC_DKOSALTHREAD_H_

namespace std {
	class mutex {
		public:
            void lock();
		    void unlock();
    };
};

namespace dk
{

namespace osal
{
	typedef const char *ThreadConfigID;
	
	class Thread {
		public:
            void start ( ThreadConfigID id );
            void *join();
	};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALTHREAD_H_ */
