/*
 * tester.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: Matt
 */


#include "tester.h"
#include "print_ts.h"
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex m;

vector<thread> threads;

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay)
{
	std::thread t1(PRINT1,s);

	for(int i = 0; i < numThreads; i++)
	{
		threads.push_back(std::thread(PRINT1,s));
	}
}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel)
{

}

/*
 * waits for all threads to complete
 */
void joinThreads()
{

}
