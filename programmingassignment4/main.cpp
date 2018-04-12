#include "bsttree.h"
#include <iostream>
using namespace std;

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