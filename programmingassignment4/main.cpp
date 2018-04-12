#include "bsttree.h"
#include <iostream>
using namespace std;

//Since this project was graded on an automatic grader, I created a personal main method to test each individual function of the 
//binary search tree. 

int main() {
	BSTree table;

	table.insert(10);
	table.insert(25);
	table.insert(9);
	table.insert(23);
	table.insert(-3);
	table.insert(14);
	table.insert(6);
	table.insert(45);
	table.insert(-3);
	table.insert(-3);
	table.insert(165);
	table.insert(-200);

	table.remove(10);
	table.remove(23);
	table.remove(25);
	table.clear();
	table.print_all();

	std::cout << "Size: " << table.size() << std::endl; // Check if n_elem is being decremented correctly.

	return 0;
}
