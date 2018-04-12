#ifndef __BSTREE_H__
#define __BSTREE_H__

#ifndef NULL
#define NULL 0x00
#endif

#include <vector>

class BSTNode {
private:
	// the integer value stored at this node
	int value;
	// count how many occurrences of this integer we have
	unsigned int count;

	BSTNode *left;
	BSTNode *right;

public:
	BSTNode(const int num) {
		count = 1;
		value = num;
		left = right = NULL;
	}

	~BSTNode() {
	}

	friend class BSTree;
	friend class MyTree; // necessary for the autograder
};

class BSTree {
protected:
	BSTNode *root;
	unsigned int n_elem;
	void removeBuddy(BSTNode *par, BSTNode *x, const int num);
	void printBuddy(BSTNode *x);
	void rangeBuddy();
	// here you can add any helper private methods
	// ...

public:
	// DO NOT change any of the public methods
	// they should remain intact, so the Autograder can grade your work

	// Q1 -- 5 pts
	// constructor/destructor of the tree
	BSTree();
	~BSTree();

	// Q2 -- 20 pts
	// if the integer already exists in the tree, just update the counter
	// otherwise make an insertion of a new value
	void insert(const int num);

	// Q3 -- 5 pts
	// returns 1 if the integer exists in the tree
	// 0 otherwise
	int contains(const int num);

	// Q4 -- 20 pts
	// if there is more than one occurrence of the integer in the tree
	// decrease the counter, otherwise delete the node
	void remove(const int num);

	// Q5 -- 5 pts
	// returns 1 if the tree is empty, 0 otherwise
	int empty();

	// Q6 -- 5 pts
	// returns how many different integers are in the tree
	unsigned int size();

	// Q7 -- 10 pts
	// removes all nodes from the tree and initializes all data members
	void clear();

	// Q8 -- 20 pts
	// returns in `range` all the integers in the interval [l,r]
	// returned values must appear in the same ordering as given by
	// a preorder traversal
	void range_search(const int l, const int r, std::vector<int> *range);

	// Q9 -- 10 pts
	// print (to the standard output) the frequency table in numerical
	// non-decreasing order using this format: one element of the tree should
	// be printed per line.  Each line must contain the integer value,
	// followed by one whitespace, followed by the number of occurrences of
	// that integer in the tree.
	// (to earn points in this question you need a correct solution for `insert`)
	void print_all();
};

#endif