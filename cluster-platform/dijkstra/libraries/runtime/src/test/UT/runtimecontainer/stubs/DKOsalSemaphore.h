#ifndef SRC_DKOSALSEMAPHORE_H_
#define SRC_DKOSALSEMAPHORE_H_

namespace dk {
namespace osal {

	class Semaphore {

		public:
			Semaphore ();
			Semaphore (uint32_t counter);

			void post();
			bool timedWaitMS(uint32_t msec);
	};
	
} /* osal */
} /* dk */

#endif /* SRC_DKOSALSEMAPHORE_H_ */
