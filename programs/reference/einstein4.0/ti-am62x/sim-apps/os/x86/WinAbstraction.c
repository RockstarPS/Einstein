#include <windows.h>
#include <stdio.h>

void WindowsSetEvent(unsigned long hEvent)
{
	SetEvent(hEvent);
}
