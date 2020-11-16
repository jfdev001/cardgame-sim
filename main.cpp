/*------------------------------------------------------------------------*
 *Author: Jared Frazier   | Date:
 *Course: CSCI 3110-003   | Due:
 *Instructor: Dr. Barbosa | Asgn Title:
 *Purpose:
 *------------------------------------------------------------------------*/

 //HEADER FILES
#include <iostream>
#include <fstream>
#include <string>
#include "priorityqueue.h"

int main()
{
    //vars
    std::ifstream read;
    int ele;
    read.open("nums.txt");

    //instantiate class
    PriorityQueue<int, MaxHeap<int>> mpq;

    //Read and enqueue
    while (read >> ele) {
        std::cout << ele << std::endl;
        mpq.enqueue(ele);
    }
    std::cout << std::endl;

    //Print the queue
    mpq.print();

    //Delete top element
    mpq.dequeue();
    std::cout << std::endl;

    //Print
    mpq.print();

    read.close();
    return 0;
}