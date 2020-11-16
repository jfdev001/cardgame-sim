#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>

//COMPARATORS:
template <typename Item_Type>
class MaxHeap {
public:
	bool compareItems(Item_Type& item1, Item_Type& item2) {
		return item1 >= item2;
	}
};

template <typename Item_Type>
class MinHeap {
public:
	bool compareItems(Item_Type& item1, Item_Type& item2) {
		return item1 <= item2;
	}
};

//template <typename data_type, typename cmp>
template <typename Item_Type, typename Comparator>
class PriorityQueue { //max priority queue for testing
private:
	int num_ele;				 //Number of elements in priority queue
	std::vector<Item_Type> heap; //template type
	Comparator cmp;

	//Heap up
	void heapUp(int child) { //heap up for max heap
		int pre_parent = child - 1; //When div 2, parent
		while (pre_parent > -1) {   //If this was parent > 0, inf loop. Currently it's root
			if (cmp.compareItems(heap[child], heap[pre_parent / 2])) {  //if child > parent
				Item_Type temp = heap[pre_parent / 2]; //Old Parent is temporary
				heap[pre_parent / 2] = heap[child];	 //New parent: old_parent = cur_child
				heap[child] = temp;					 //Old parent is now child of New Parent
			}
			child = pre_parent / 2;   //Child for next comparison is Cur_Parent
			pre_parent = child - 1; //Pre_parent of cur_parent (next child)
		}
	}

	//Heap down
	void heapDown(int replace_top) { //heap down for max heap
		Item_Type temp;			     //Temporary variable for swapping elements
		int i = 0;			         //Start index
		heap[i] = heap[replace_top]; //Bubble -- precondition to while()
		bool in_range = true;        //In range index

		//While bubble greater than both left and right child
		while (in_range
			&& (heap[i] < heap[2 * i + 1] || heap[i] < heap[2 * i + 2])) {
			if (heap[2 * i + 2] > heap[2 * i + 1]) { //right > left
				temp = heap[2 * i + 2];        //Store right_child
				heap[2 * i + 2] = heap[i]; //right_child is now bubble
				heap[i] = temp;			   //Parent is now the bigger right_child
				i = 2 * i + 2;			   //Bubble index is now right_child
			}
			else { //left_child > right_child
				temp = heap[2 * i + 1];    //Store left_child
				heap[2 * i + 1] = heap[i]; //left_child is now bubble
				heap[i] = temp;            //Parent is now the bigger left_child
				i = 2 * i + 1;             //Bubble index is now left_child
			}
			if (i >= num_ele) { //Index in bounds?
				in_range = false;
			}
		}
	}

public:
	//Constructor
	PriorityQueue() {
		num_ele = 0;
		heap.resize(50);
	}

	//Adds item and places it in the proper heap order
	void enqueue(Item_Type item) {
		heap[num_ele] = item;
		heapUp(num_ele);      //Current size of heap is index to insert
		num_ele++;            //increment current size of heap
	}

	//Remove highest priority item
	void dequeue() {
		heapDown(num_ele - 1); //Replace the top of the heap
		num_ele--;			   //Decrement number of elements
	}

	//True if queue is empty
	bool empty() {
		if (num_ele == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//Display items in heap index 0 to num_ele - 1
	void print() {
		for (int i = 0; i < num_ele; i++) {
			std::cout << heap[i] << std::endl;
		}
	}
};
#endif
