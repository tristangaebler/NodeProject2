/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: tgae6529
 */

#include "NodeController.h"
#include <iostream>
#include <stdlib.h>

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
void NodeController :: start()
{
    tryTree();
}

void NodeController::tryTree()
{
    CTECBinaryTree<int> testTree;
    testTree.insert(7);
    testTree.insert(10);
    testTree.insert(-5);
}

void NodeController::testLists()
{
    CTECList<int> myList;
    myList.addToFront(7); //Testing addToFront
    cout << "Get front should be 7 and is: " << myList.getFront() << endl;
    
    myList.addAtIndex(1, 56); //Testing add at index
    cout << "Add at index should be 56 and is: " << myList.getAtIndex(1) << endl;
    
    myList.addToEnd(23); //Test add to end
    cout << "Add to end should be 23 and is: " << myList.getEnd() << endl;
    
    myList.set(2, 34); //Testing the set method
    cout << "Set method should return 23 and is returning: " << myList.getAtIndex(2) << endl;
    
    myList.removeFront(); //Testing the removeFront method
    cout << "There should be 7 in front and front has: " << myList.getFront() << endl;
    
    myList.removeAtIndex(2); //Testing the remove at index
    cout << "The list should be shrunk by one: " << myList.getSize() << endl;
    
    myList.removeEnd(); //Testing remove from End method
    cout << "The end should be 7 and is:  " << myList.getEnd() << endl;
   
    cout << "The size of the list is: " << myList.getSize() << endl; //Testing the getSize method
}

void NodeController::checkSorts()
{
    /*
     *Create list of array
     *fill with random
     *fill with orderd
     *start time
     *sort
     *stop time
     *print
     */
    
    CTECArray<int> sortNumArray(5);
    CTECList<int> sortNumList;
    int cPlusPLusArray[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        sortNumArray.set(spot, randomValue);
        sortNumList.addToEnd(randomValue);
        cPlusPLusArray[spot] = randomValue;
    }
    
    Timer listTimer;
    listTimer.startTimer();
    sortNumList.selectionSort();
    listTimer.stopTimer();
    listTimer.displayTimerInfo();
    listTimer.resetTimer();
    
    listTimer.resetTimer();
    listTimer.startTimer();
    
}

void NodeController::doMergeSort()
{
    mergeData = new int[100000000];
    for(int spot = 0; spot < 100000000; spot++)
    {
        int randomValue = rand();
        mergeData[spot] = randomValue;
    }
    for(int spot = 0; spot < 100000000; spot++)
    {
        cout << mergeData[spot] << ",";
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    for(int spot = 0; spot < 100000000; spot++)
    {
        cout << mergeData[spot] << ",";
    }
    
    delete [] mergeData;
}

void NodeController::mergeSort(int dataArray[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size / 2;
        sizeTwo = size - sizeOne;
        
        mergeSort(dataArray, sizeOne);
        mergeSort(dataArray + sizeOne, sizeTwo);
        
        merge(dataArray, sizeOne, sizeTwo);
        
    }
    
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    while ((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp [copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    
    while (copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne) [copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController::quickSort(int first, int last)
{
    int pivotIndex;
    int sizeOne;
    int sizeTwo;
    if(first <  last)
    {
        pivotIndex = partition(first, last);
        quickSort(first, pivotIndex-1);
        quickSort(pivotIndex, last);
        
    }
}

int NodeController::partition(int first, int last)
{
    
    int pivot;
    int index, smallIndex;
    swap(first, (first +last) / 2 );
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    
    swap(first, smallIndex);
    return smallIndex;
    
}

void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::doQuick()
{
    
    mergeData = new int[500];
    for(int spot = 0; spot < 500; spot++)
    {
        int randomValue = rand();
        mergeData[spot] = randomValue;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 500);
    mergeTimer.stopTimer();
    
    delete [] mergeData;
}


















