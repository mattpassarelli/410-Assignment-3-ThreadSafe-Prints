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
#include <iostream>
#include <chrono>

using namespace std;

mutex m;


vector<thread> threads;
bool areCancelled = false;

/*
 * This is supposed to be a helper function so we can call the needed PRINT function in print_ts.cpp
 * Unfortunately, the two ways I see of doing is
 * 1) Call a helper function and use a switch statement to pick the function
 * or
 * 2) Use a switch statement in the startThreads and then have 5 helper functions lol
 *
 * EVEN WORSE, is that I have to repeat code in each case because if I try to consolidate it into a single function
 * that can pick all 5 PRINT functions, it'll require ANOTHER switch statement and would be just as messy looking
 *
 * Will work on it though :/
 */
void func(std::string s, WHICH_PRINT wp, int numTimesToPrint,
		int millisecond_delay) {

	switch (wp) {
	case P1:
		for (int i = 0; i < numTimesToPrint; i++) {
			//wait for the certain delay to go ahead and print
			this_thread::sleep_for(chrono::milliseconds(millisecond_delay));

			//if the threads are set to cancel, reset the String to print to USER_CHOSE_TO_CANCEL
			//otherwise, if false, we print as normal
			if (!areCancelled) {
				m.lock();
				PRINT1(s);
				m.unlock();
			} else if (areCancelled) {
				m.lock();
				s = USER_CHOSE_TO_CANCEL;
				PRINT1(s);
				m.unlock();
			}
		}
		break;
	case P2:
		for (int i = 0; i < numTimesToPrint; i++) {
			//wait for the certain delay to go ahead and print
			this_thread::sleep_for(chrono::milliseconds(millisecond_delay));

			//if the threads are set to cancel, reset the String to print to USER_CHOSE_TO_CANCEL
			//otherwise, if false, we print as normal
			if (!areCancelled) {
				m.lock();
				PRINT2(s, s);
				m.unlock();
			} else if (areCancelled) {
				m.lock();
				s = USER_CHOSE_TO_CANCEL;
				PRINT2(s, s);
				m.unlock();
			}
		}
		break;

	case P3:
		for (int i = 0; i < numTimesToPrint; i++) {
			//wait for the certain delay to go ahead and print
			this_thread::sleep_for(chrono::milliseconds(millisecond_delay));

			//if the threads are set to cancel, reset the String to print to USER_CHOSE_TO_CANCEL
			//otherwise, if false, we print as normal
			if (!areCancelled) {
				m.lock();
				PRINT3(s, s, s);
				m.unlock();
			} else if (areCancelled) {
				m.lock();
				s = USER_CHOSE_TO_CANCEL;
				PRINT3(s, s, s);
				m.unlock();
			}
		}
		break;
	case P4:
		for (int i = 0; i < numTimesToPrint; i++) {
			//wait for the certain delay to go ahead and print
			this_thread::sleep_for(chrono::milliseconds(millisecond_delay));

			//if the threads are set to cancel, reset the String to print to USER_CHOSE_TO_CANCEL
			//otherwise, if false, we print as normal
			if (!areCancelled) {
				m.lock();
				PRINT4(s, s, s, s);
				m.unlock();
			} else if (areCancelled) {
				m.lock();
				s = USER_CHOSE_TO_CANCEL;
				PRINT4(s, s, s, s);
				m.unlock();
			}
		}
		break;
	case P5:
		for (int i = 0; i < numTimesToPrint; i++) {
			//wait for the certain delay to go ahead and print
			this_thread::sleep_for(chrono::milliseconds(millisecond_delay));

			//if the threads are set to cancel, reset the String to print to USER_CHOSE_TO_CANCEL
			//otherwise, if false, we print as normal
			if (!areCancelled) {
				m.lock();
				PRINT5(s, s, s, s, s);
				m.unlock();
			} else if (areCancelled) {
				m.lock();
				s = USER_CHOSE_TO_CANCEL;
				PRINT5(s, s, s, s, s);
				m.unlock();
			}
		}
		break;
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

