/*
 * print_ts.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: Matt
 */

#include "print_ts.h"
#include <iostream>

using namespace std;

void PRINT1(std::string &txt) {
	cout << txt << endl;
}

void PRINT2(std::string &txt, std::string &txt1) {
	cout << txt << txt1 << endl;

}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
	cout << txt << txt1 << txt2 << endl;

}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3) {
	cout << txt << txt1 << txt2 << txt3 << endl;

}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3, std::string &txt4) {
	cout << txt << txt1 << txt2 << txt3 << txt4 << endl;
}
