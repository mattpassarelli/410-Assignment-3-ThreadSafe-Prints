/*
 * main.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: Matt
 */

#include "tester.h"
#include "print_ts.h"
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int main() {
	string s1 = "Squat";
	string s2 = "Pray";
	string s3 = "Leap";
	string s4 = "AHHHHH";
	string s5 = "Touchdown";

	startThreads(s1, 1, P1, 1, 400);
	startThreads(s2, 1, P2, 1, 200);
	startThreads(s3, 1, P3, 1, 100);
	startThreads(s4, 1, P4, 1, 100);
	startThreads(s5, 1, P5, 10, 500);

	this_thread::sleep_for(chrono::milliseconds(500));
	setCancelThreads(true);



	joinThreads();

	return 0;
}
