#include "bsttree.h"
#include <iostream>
using namespace std;

BSTree::BSTree() {
	root = NULL;
	n_elem = 0;
}

BSTree::~BSTree() {
	BSTree::clear();
}

void BSTree::removeBuddy(BSTNode *par, BSTNode *x, const int num) {//par is parent node, x is node to be checked, num is value to be removed
	if (x == NULL) {//basecase
		return;
	}
	if (x->value == num && x->count == 1) {//only when the node would be deleted (i.e. count is at one)
		//This is for cases 1 and 2 where there is only one child or no children.
		if (x->left == NULL || x->right == NULL) {
			BSTNode *t = x->left;
			if (x->left == NULL) {//assignes the temp node to the non-empty child or to null if both are empty
				t = x->right;
			}
			if (par != NULL) {//if the temp is not the root
				if (par->left == x) {//If the val to be removed is on the left
					par->left = t;//swap
					delete x;//delete
					n_elem--;//Subtracts the deleted element
					return;
				}
				else {//if val is on the right
					par->right = t;//swamp
					delete x;//delete
					return;
				}
			}
			else {// if the temp is the root
				root = t;
				n_elem--;
				return;
			}
		}
		else { //For case #3
			BSTNode *temp = x->right;//Goes to the right first to get a val bigger then the one replaced
			while (temp->left != NULL) {//Then goes to the left to find the val closest to the removed value
				temp = temp->left;//loops to find the replacement closest to the removed value
			}
			int tempVal = x->value;
			x->value = temp->value;//swaps
			temp->value = tempVal;
			removeBuddy(x, x->right, tempVal);//removes the swapped value
			n_elem--;//subtracts element
			return;
		}

	}
	else if (x->value == num && x->count > 1) {//for if a value has multiple instances on the count var.
		x->count -= 1;
		return;
	}
	//Loops through the tree until it either hits a null value or hits the number.
	if (num > x->value) {
		removeBuddy(x, x->right, num);
	}
	else {
		removeBuddy(x, x->left, num);
	}
	return;
}
void BSTree::printBuddy(BSTNode *x) {//inorder traversal
	while (x != NULL) {
		printBuddy(x->left);
		cout << x->value << " " << x->count << endl;
		printBuddy(x->right);
		return;
	}
	return;
}

void BSTree::insert(const int num) {
	if (root == NULL) {
		BSTNode* first = new BSTNode(num);
		root = first;
		n_elem++;
		return;
	}
	bool done = false;//This will keep the loop going until it finds the spot for the element
	BSTNode* place = root;
	while (!done) {
		if (place->value == num) {//if the element already exists
			place->count += 1;
			done = true;
		}
		else if (num > place->value) {//if the number is bigger then the current element
			if (place->right == NULL) {//places a new node
				BSTNode* node = new BSTNode(num);
				place->right = node;
				n_elem++;
				done = true;
			}
			else {//goes deeper in the tree
				place = place->right;
			}
		}
		else if (num < place->value) {//num is less then the current node
			if (place->left == NULL) {//places new node
				BSTNode* node = new BSTNode(num);
				place->left = node;
				n_elem++;
				done = true;
			}
			else {//goes further in the array
				place = place->left;
			}
		}
		else {
			done = true;//I put this here to stop a hypothetical infinite loop. I don't know if this is necisarry but it doesn't seem to hurt the program.
		}
	}
}

int BSTree::contains(const int num) {
	if (root == NULL) {
		return 0;
	}
	//I reused the bulk of code from insert to find the value for contains, only thing I changed was what
	//the function does when it finds or doesn't find the value.
	bool done = false;
	BSTNode* place = root;
	while (!done) {
		if (place->value == num) {
			return 1;
		}
		else if (num > place->value) {
			if (place->right == NULL) {
				return 0;
			}
			else {
				place = place->right;
			}
		}
		else if (num < place->value) {
			if (place->left == NULL) {
				return 0;
			}
			else {
				place = place->left;
			}
		}
		else {
			return 0;//same thing as in insert, just to stop a potentential infinite loop from occuring. 
		}
	}
	return 0;
}


void BSTree::remove(const int num) {
	if (root == NULL) {
		return;
	}
	removeBuddy(NULL, root, num);//helper func
}

int BSTree::empty() {
	if (root == NULL) {
		return 1;
	}
	return 0;
}

unsigned int BSTree::size() {
	return n_elem;
}

void BSTree::clear() {
	while (root != NULL) {//deletes the root until all leaves are gone
		remove(root->value);
	}
	root = NULL;
	n_elem = 0;
}

void BSTree::range_search(const int l, const int r, std::vector<int> *range) {

}

void BSTree::print_all() {
	BSTNode *x = root;
	printBuddy(root);//helper function
}