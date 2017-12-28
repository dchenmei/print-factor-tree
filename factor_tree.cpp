#include "factor_tree.hpp"

#define NO_FACTOR '+' /* Used to keep track of empty slots in factot tree */

Factor_Tree::Factor_Tree(int r, bool even): root(r) 
{
	if (even) 
	{
		construct_even_factor_tree(r);
	}
	else 
	{
		construct_factor_tree(r);
	}
}

void Factor_Tree::print_factor_tree()
{

}

int Factor_Tree::get_root()
{
	return root;
}

vector<int> Factor_Tree::get_factor_tree()
{
	return factor_tree;
}

void Factor_Tree::set_root(int i)
{
	root = i;
}

/* Uneven factor tree construct using greedy algorithm */
void Factor_Tree::construct_factor_tree(int r)
{
    /* Keep track of numbers we still need to factor */
	vector<int> not_factored;
	not_factored.push_back(r); /* Push root to start */
	
	int i = 5;	
	int curr;
	while (i--)
	{   
		cout << i << endl;
		for (int x : not_factored)
		{
			cout << x << " ";
		}
		cout << endl;
		/* Instead of using the for loop, just keep checking the head to prevent
*                out of bound shit storm */

		/* Process and pop value */
		curr = not_factored[0];
		cout << "curr: " << curr << endl;


		factor_tree.push_back(curr); /* Add to factor tree */

		/* If not prime value, we need to factor further */
		if (greatest_factor(curr) != 0)
		{
		    cout << "X w/:" << greatest_factor(curr) <<  endl;
			curr = greatest_factor(curr);
			not_factored.push_back(curr);
			not_factored.push_back(r / curr);
		
		}
	
		not_factored.erase(not_factored.begin()); /* runs O(n), don't worry about it */

	}

}

int main()
{
	Factor_Tree *tree = new Factor_Tree(48, false);
	/*
	vector<int> tv = tree->get_factor_tree();

	for (int x : tv)
		cout << x << " ";
	*/
	
	return 0;
}
