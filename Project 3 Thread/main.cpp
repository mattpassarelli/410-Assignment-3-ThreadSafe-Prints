/*
 * main.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: Matt
 */

#include "tester.h"
#include "print_ts.h"
#include <string>

using namespace std;

int main()
{
	string s1 = "Squat";
	string s2 = "Pray";
	string s3 = "Leap";
	string s4 = "Aim";
	string s5 = "Touchdown";

	startThreads(s1, 1, P1, 5, 5);
	joinThreads();

	return 0;
}
