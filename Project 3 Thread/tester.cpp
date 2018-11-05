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
#include <chrono>
#include <iostream>
#include <mutex>

using namespace std;

vector<thread> threads;
bool areCancelled = false;

mutex mut;

/*
 * This is supposed to be a helper function so we can call the needed PRINT function in print_ts.cpp
 * Unfortunately, the two ways I see of doing is
 * 1) Call a helper function and use a switch statement to pick the function
 * or
 * 2) Use a switch statement in the startThreads and then have 5 helper functions lol
 *
 *--------------------I fixed this :)-------------------------
 * EVEN WORSE, is that I have to repeat code in each case because if I try to consolidate it into a single function
 * that can pick all 5 PRINT functions, it'll require ANOTHER switch statement and would be just as messy looking
 *
 * Will work on it though :/
 *--------------------I fixed this :)-------------------------
 *
 * So turns out, my dumbass is just dumb and needed to think some more about how to consolidate the code.
 * I would have left the old code commented out, but it honestly took up so much space, it wasn't worth the KB of storage needed lol.
 */
void func(std::string s, WHICH_PRINT wp, int numTimesToPrint,
		int millisecond_delay) {

	for (int i = 0; i < numTimesToPrint; i++) {

		//lock the thread just so multiple threads aren't trying to
		//check at the same time
		mut.lock();
		if (areCancelled) {
			s = USER_CHOSE_TO_CANCEL;
			mut.unlock();
		}
		mut.unlock();

		switch (wp) {
		case P1:
			PRINT1(s);
			break;
		case P2:
			PRINT2(s, s);
			break;
		case P3:
			PRINT3(s, s, s);
			break;
		case P4:
			PRINT4(s, s, s, s);
			break;
		case P5:
			PRINT5(s, s, s, s, s);
			break;
		}

		//wait for the certain delay to go ahead and print
		this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
	}
}

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay) {

	for (int i = 0; i < numThreads; i++) {
		threads.push_back(
				std::thread(func, s, wp, numTimesToPrint, millisecond_delay));
	}
}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	if (bCancel) {
		areCancelled = true;
	} else {
		areCancelled = false;
	}
}

/*
 * waits for all threads to complete
 */
void joinThreads() {

	for (auto& t : threads) {
		t.join();
	}
}

