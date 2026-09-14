#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "DKOsalTimer.h"

using namespace std;
using namespace dk;
using namespace osal;
static uint32_t timercnt = 0;
void timerstop();


class TimerListenerCbk_1 : public dk::osal::ITimerListener
{
public:
    void onTimeout ( const Timer &timer ){
        cout << "THIS IS MY TIMER1 CALLBACK with timeout" << endl;
    }
};

class TimerListenerCbk_2 : public dk::osal::ITimerListener
{
public:
    void onTimeout ( const Timer &timer ){

        cout << "THIS IS MY TIMER2 CALLBACK with timeout" << endl;

        timercnt++;
        if(timercnt > 4)
        {

            timerstop();

        }
    }
};

TimerListenerCbk_1 oTimer1Cbk;
TimerListenerCbk_2 oTimer2Cbk;

Timer oTimer_1(oTimer1Cbk);
Timer oTimer_2(oTimer2Cbk);

int main( int argc, char *argv[] )
{

    uint32_t timeOut;
    uint32_t timeInterval;

    cout << "***********************************************************************\n" << endl;
    cout << "**                            Timer test                             **\n" << endl;
    cout << "***********************************************************************\n" << endl;

    /* One-shot timer */
    oTimer_1.start(1000);
    
    timeOut  = oTimer_1.getTimeout();
    cout << "timerOut value of timer_1: " << timeOut << "\n";

    timeInterval = oTimer_1.getTimerInterval();
    cout << "Timer_1 timer interval : " << timeInterval << "\n\n";

    /* periodic timer */
    oTimer_2.start(200, 100);

    timeOut  = oTimer_2.getTimeout();
    cout << "timerOut value of timer_2: " << timeOut << "\n";

    timeInterval = oTimer_2.getTimerInterval();
    cout << "Timer_2 timer interval : " << timeInterval << "\n\n";

    std::this_thread::sleep_for ( std::chrono::seconds ( 5 ) );

    return 0;
}

void timerstop()
{

    oTimer_2.stop();

}
