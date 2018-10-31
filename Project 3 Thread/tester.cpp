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

void func(std::string s, WHICH_PRINT wp, int numTimesToPrint,
		int millisecond_delay) {

	switch (wp) {
	case P1:
		for (int i = 0; i < numTimesToPrint; i++) {
			//wait for the certain delay to go ahead and print
			this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
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

		}
		break;
	case P3:
		for (int i = 0; i < numTimesToPrint; i++) {

		}
		break;
	case P4:
		for (int i = 0; i < numTimesToPrint; i++) {

		}
		break;
	case P5:
		for (int i = 0; i < numTimesToPrint; i++) {

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

