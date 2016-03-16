/*
 * NodeRunner.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: tgae6529
 */

#include "NodeController.h"
/*
 * The main method that starts the program. It declares a new NodeController and calls it baseController. BaseController calls start().
 */
int main() {
	NodeController * baseController = new NodeController();
	baseController->start();
	return 0;
}


