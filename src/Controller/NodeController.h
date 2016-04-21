/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: tgae6529
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECList.cpp"
#include "../Model/CTECList.h"
#include "../Model/CTECBinaryTree.cpp"
#include <string>

using namespace std;

class NodeController {
private :
	CTECArray<int> * myIntArray;
	CTECList<int> * numbers;
	Timer arrayTimer;
    int * mergeData;
	void testLists();
    void checkSorts();
    void doMergeSort();
    void mergeSort(int dataArray[], int size);
    void merge(int data[], int sizeOne, int sizeTwo);
    void doBogo();
    void quickSort(int first, int last);
    int partition(int first, int last);
    void swap(int first, int second);
    void doQuick();
public:
	NodeController();
	virtual ~NodeController();
	void start();
    void tryTree();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
