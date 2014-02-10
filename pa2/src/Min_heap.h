/*
 * Min_heap.h
 *
 *  Created on: Feb 10, 2014
 *      Author: vicentecarrillo
 */

#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_


struct Node
{
	char value;
	int frequency;
	Node* left;
	Node* right;
	Node(char val, int freq) : value(val), frequency(freq), left(nullptr), right(nullptr) {}
};

class Min_heap {
private:
	Node* root;

public:
	bool insert(char val, int freq);
	bool delete_min();
	bool merge(Node* heap);
};



#endif /* MIN_HEAP_H_ */
