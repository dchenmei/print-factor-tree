/*******************************************
 *  UI
 *
 *  Author: swolewizard
 ******************************************/

#include "factor_tree.hpp"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int root;
	cout << "Please enter root: ";
	cin >> root;

	/* Input validation */
	if (root < 1)
	{
		cout << "Root can only be a positive integer, try again." << endl;
		return -1;
	}

	Factor_Tree *tree = new Factor_Tree(root);
	tree->print();

	return 0;
}
