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
//END COMPARATORS


//PRIORITYQUEUE:
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
	void heapDown(int end) { //heap down for max heap
		
		//Extract element from the root
		int cur = 0;
		heap[cur] = heap[end];
		Item_Type temp;
		bool is_leaf = false;
		
		//while bubble is not a leaf and it is < any of its children
		while (!is_leaf 
		       && (!cmp.compareItems(heap[cur], heap[2*cur+1])
		       ||!cmp.compareItems(heap[cur], heap[2*cur+2]))) {
		   if (cmp.compareItems(heap[2*cur+1], heap[2*cur+2])) { //left over right
				temp = heap[2*cur+1];
				heap[2*cur+1] = heap[cur];
				heap[cur] = temp;
				cur = 2*cur+1; //Bubble (cur) is now in left child
		   }
		   else {
			   	temp = heap[2*cur+2];
				heap[2*cur+2] = heap[cur];
				heap[cur] = temp;
				cur = 2*cur+2; //Bubble (cur) is now in right child
		   }
		   if (2*cur+1 >= num_ele){ //check if leaf node
			   is_leaf = true;
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
		std::cout << "Dequeued " << heap[0] << " ";
	    num_ele--;		   //Decrement number of elements
		heapDown(num_ele); //Replace the top of the heap
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
			std::cout << heap[i];
		}
	}
};
//END PRIORITYQUEUE
#endif
