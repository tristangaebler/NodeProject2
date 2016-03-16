/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: tgae6529
 */

#include "NodeController.h"
#include <iostream>

/*
 * This is the Constructor of the NodeController class. We are giving the CTECArray 5 indexes or spots.
 */
NodeController::NodeController() {

	myIntArray = new CTECArray<int>(5);
	numbers = new CTECList<int>();
}
/*
 * This is the destructor for the NodeController class. Currently nothing is happening in it. I do not fully understand the destructor.
 */
NodeController::~NodeController() {
	// TODO Auto-generated destructor stub
}
/*
 * This is the start method that is void. We are giving the CTECArray values. Then we print the values out using cout <<.
 */

void NodeController::testLists() {
	numbers->addToFront(3);
	numbers->addToEnd(8);

	cout << "End should be 8 and beginning should be 3" << numbers->getEnd() <<endl;
}
void NodeController :: start() {

	testLists();

	arrayTimer.startTimer();

	cout << "TESTING 123" << endl;

	for(int index = 0; index < myIntArray->getSize(); index++) {
		cout << "build" << index << endl;
		myIntArray->set(index, (23 * index));

	}
	for(int index = 0; index < myIntArray->getSize(); index++) {
		cout << "export" << index << endl;
		cout << "These are some integers that " << index << "contain " << myIntArray->get(index) << endl;
	}

	cout << "TESTING 123" << endl;

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();
}

