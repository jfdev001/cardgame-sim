/*------------------------------------------------------------------------*
 *Author: Jared Frazier   | Date: 11/15/2020
 *Course: CSCI 3110-003   | Due:  11/16/2020
 *Instructor: Dr. Barbosa | Asgn Title: proj7
 *Purpose: Priority queue (binary heap) of Card objects
 *with max and min comparator (tells what kind of queue to be)
 *------------------------------------------------------------------------*/

 //HEADER FILES
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "priorityqueue.h"
#include "card.h"

int main()
{
    //Vars
    std::ifstream read;
    int seed;
    read.open("pqseed.txt");

    //Set seed
    read >> seed;
    srand(seed);

    //Instantiate min priority queue
    PriorityQueue<Card, MinHeap<Card>> min_pq;

    //Instantiate max priority queue
    PriorityQueue<Card, MaxHeap<Card>> max_pq;

    //Instantiate spades deck and hearts deck
    Card spadesDeck[13];
    Card heartsDeck[13];
    for (int i = 0; i < 13; i++) {
        Card new_spade(i+1, spades);
        Card new_heart(i+1, hearts);
        spadesDeck[i] = new_spade;
        heartsDeck[i] = new_heart;
    }

    //Shuffle the decks
    std::random_shuffle(std::begin(spadesDeck), std::end(spadesDeck));
    std::random_shuffle(std::begin(heartsDeck), std::end(heartsDeck));

    //Enqueue spades into max priority queue
    for (int i = 0; i < 13; i++) {
        max_pq.enqueue(spadesDeck[i]);
        std::cout << "Enqueued " << spadesDeck[i];
        max_pq.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    //Dequeue spades from max priority queue
    while (!max_pq.empty()) {
        max_pq.dequeue();
        max_pq.print();
        std::cout << std::endl;
    }
    std::cout << "Max Heap Empty" << std::endl << std::endl;

    //Enqueue hearts into min priority queue
    for (int i = 0; i < 13; i++) {
        min_pq.enqueue(heartsDeck[i]);
        std::cout << "Enqueued " << heartsDeck[i];
        min_pq.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Dequeue spades from max priority queue
    while (!min_pq.empty()) {
        min_pq.dequeue();
        min_pq.print();
        std::cout << std::endl;
    }
    std::cout << "Min Heap Empty" << std::endl;

    read.close();
    return 0;
}
