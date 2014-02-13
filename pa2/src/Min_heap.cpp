/*
 * Min_heap.cpp
 *
 *  Created on: Feb 12, 2014
 *      Author: vicentecarrillo
 */
#include "Min_heap.h"
#include <deque>

using namespace std;

Min_heap::Min_heap() {}

int Min_heap::parent(int index)
{
	return (index + 1)/2 + 1;
}

int Min_heap::left(int index)
{
	return 2 * (index + 1) - 1;
}

int Min_heap::right(int index)
{
	return 2 * (index +1);
}

bool Min_heap::is_leaf(int index)
{
	if (left(index) > (tree.size() - 1))
		return true;
	return false;
}

int Min_heap::count_elements()
{
	return tree.size();
}

char Min_heap::get_element(int index)
{
	return tree[index].value;
}

void Min_heap::insert(char val, int frequency)
{
	Node new_node(val,frequency);
	tree.push_back(new_node);
	//TODO
	// percolate up
}

char Min_heap::delete_min()
{
	char min = tree[0].value;
	tree[0] = tree.back();
	tree.pop_back();
	//TODO
	// percolate down
	return min;
}



