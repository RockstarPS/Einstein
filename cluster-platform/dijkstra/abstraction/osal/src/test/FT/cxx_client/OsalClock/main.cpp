#include <iostream>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "DKOsalClock.h"

using namespace std;
using namespace dk::osal;

void print(string str, timespec &ts)
{
	cout<<str<<":seconds: "<<ts.tv_sec<<endl;
	cout<<str<<":nanoseconds: "<<ts.tv_nsec<<endl;
}

int main(int argc, char* argv[])
{
	timespec ts, ts1, ts2;

	/**************************************************************************/
	//print current system time
	cout<<"system time in ns: "<<std::chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count()<<endl;

	//Get current system time and store value in struct ts
	Clock::getSystemTime(ts);
	//print current system time value in sec & ns obtained by getSystemTime() API, stored in ts structure.
	print("getSystemTime()", ts);
	(void)getchar();

	//Get monotonic timestamp and store the values in struct ts1
	Clock::getMontonicTime(ts1);
	//print monotonic timestamp values in sec and ns obtained by getMontonicTime() API, stored in ts1 structure.
	print("getMontonicTime()", ts1);
	(void)getchar();
	/**************************************************************************/


	/**************************************************************************/
	ts2.tv_sec = 10;
	ts2.tv_nsec = 200000000;

	//reset system clock as per ts2 timespec value
	clock_settime(CLOCK_REALTIME, &ts2);

	cout<<"sleeping for 5 sec.."<<endl;
	sleep(5);

	//print current system time after system clock reset
	cout<<"After system clock reset: system time in ns: "<<std::chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count()<<endl;

	//Get current system time and store value in struct ts after resetting system clock as per ts2 member values.
	Clock::getSystemTime(ts);
	//print current system time value in sec & ns obtained by getSystemTime() API after system clock reset, stored in ts structure.
	print("After system clock reset: getSystemTime()", ts);
	(void)getchar();

	//Get monotonic timestamp and store the values in struct ts1 after resetting system clock as per ts2 member values.
	Clock::getMontonicTime(ts1);
	//print monotonic timestamp values in sec and ns obtained by getMontonicTime() API after system clock reset, stored in ts1 structure.
	print("After system clock reset: getMontonicTime()", ts1);

	(void)getchar();
	/**************************************************************************/


	/**************************************************************************/
	//reset structure ts2 value to 0
	ts2.tv_sec = 0;
	ts2.tv_nsec = 0;
	uint32_t msec = 5500; 			//5.5 sec

	//add time offset in millisec to struct ts2
	Clock::addTimeOffsetMS(msec, ts2);
	//print ts2 value after adding of msec offset.
	print("addTimeOffsetMS()", ts2);

	(void)getchar();
	/**************************************************************************/


	/**************************************************************************/
	uint32_t usec = 10500000;		//10.5 sec
	ts2.tv_sec = 0;
	ts2.tv_nsec = 0;

	//add time offset in microsec to struct ts2
	Clock::addTimeOffsetUS(usec, ts2);
	//print ts2 value after adding of usec offset.
	print("addTimeOffsetUS", ts2);
	(void)getchar();
	/**************************************************************************/


	/**************************************************************************/
	ts = {10,0}; //reset ts.sec to 10 and ts.nsec to 0
	ts1 = {5,0}; //reset ts1.sec to 5 and ts1.nsec to 0

	// Get time delta in microseconds between two timespecs.
	int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
	cout<<"getTimeDiffUS(): Difference b/w timespec ts1 & timepec ts is: "<<time_del<<endl;
	/**************************************************************************/

	return 0;
}
