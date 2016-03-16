/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: tgae6529
 */

#include "Timer.h"
#include <iomanip>
#include <iostream>
using namespace std;

Timer::Timer() {
	// TODO Auto-generated constructor stub

	executionTime = 0;
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

void Timer::displayTimerInfo() {

	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " μs (microseconds) for the code " << endl;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC << " seconds" << endl;

}

void Timer::startTimer() {
	executionTime = clock();
}

void Timer::stopTimer() {
	executionTime = clock() - executionTime;
}

void Timer::resetTimer() {
	executionTime = 0;
}

long Timer::getExecutionTimeInMicroseconds() {
	return executionTime;
}


