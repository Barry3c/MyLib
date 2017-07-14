//============================================================================
// Name        : TestingBreakpoints.cpp
// Author      : kav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define _WIN32_WINNT 0x502

#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


#include <iostream>
using namespace std;

/*******************************************************************************************************************/
/* macros                                                                                                          */
/*******************************************************************************************************************/

#if defined(_WIN64) || defined(__x86_64__)
# define REGTYPE     DWORD64
#else
# define REGTYPE     DWORD
#endif

/*******************************************************************************************************************/
/* typedefs                                                                                                        */
/*******************************************************************************************************************/
/* general threads API return type */
typedef enum {
    THREAD_OK = 0,
    THREAD_NOT_OK,
    THREAD_ERROR,
    THREAD_TIMEOUT
} thread_return_t;

/* thread handle type */
typedef HANDLE  thread_t;

/* exception handler function type */
typedef LPTOP_LEVEL_EXCEPTION_FILTER thread_exception_handler_t;
LPTOP_LEVEL_EXCEPTION_FILTER thread_saved_exception_handler_p = NULL;



/*******************************************************************************************************************/
/* functions: exception handler                                                                                    */
/*******************************************************************************************************************/
LONG WINAPI exceptionhandler(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
    cout<<"\n\n Jarvis:We've hit exception handler boss\n\n";
    fflush(stdout);
    return SHUTDOWN_NORETRY;
}


thread_return_t thread_set_exception_handler(thread_exception_handler_t func_p)
{
    //thread_saved_exception_handler_p = SetUnhandledExceptionFilter(func_p);
	AddVectoredExceptionHandler(1, func_p);

    return THREAD_OK;
}


int Func_5()
{
	int a = 0XA0A0A0A0, b = 0xB0B0B0B0;
	int *p = 0;
	*p = 0;
	a += (b & 0);
	return a;
}
int Func_4()
{
	int a = 0XA0A0A0A0, b = 0xB0B0B0B0;
	Func_5();
	a += (b & 0);
	return a;
}
int Func_3()
{
	int a = 0XA0A0A0A0, b = 0xB0B0B0B0;
	Func_4();
	a += (b & 0);
	return a;
}
int Func_2()
{
	int a = 0XA0A0A0A0, b = 0xB0B0B0B0;
	Func_3();
	a += (b & 0);
	return a;
}
int Func_1()
{
	int a = 0XA0A0A0A0, b = 0xB0B0B0B0;
	Func_2();
	a += (b & 0);
	return a;
}


int main() {
 	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    thread_set_exception_handler(exceptionhandler);
    Func_1();

	return 0;
}
