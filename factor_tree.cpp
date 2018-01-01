#include "factor_tree.hpp"

#define NO_FACTOR -1 /* Used to keep track of empty slots in factor tree */

Factor_Tree::Factor_Tree(int r): root(r) 
{
	construct_factor_tree(r);
}

void Factor_Tree::print()
{
	bool print_val = true;
	for (int factor : factor_tree)
	{
		if (factor == NO_FACTOR)
		{
			if (print_val)
			{
				cout << endl;
				print_val = false;
			}
		}
		else
		{
			cout << factor << " ";
			print_val = true;
		}
	}
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
	
	while (!not_factored.empty())
	{   
		/* Instead of using the for loop, just keep checking the head to prevent
*                out of bound shit storm */

		/* Process and pop value */
		int curr = not_factored[0];
		int curr_factor = greatest_factor(curr);
		factor_tree.push_back(curr); /* Add to factor tree */

		/* No factor value, push placeholder in factor_tree */
		if (curr == NO_FACTOR)
		{
			factor_tree.push_back(NO_FACTOR);
		}
		/* Prime, no factor */
		else if (!curr_factor)
		{
			not_factored.push_back(NO_FACTOR);
		}
		/* Not prime or no factor, factor further */
		else 
		{
			not_factored.push_back(curr_factor);
			not_factored.push_back(curr / curr_factor);
		}
	
		not_factored.erase(not_factored.begin()); /* runs O(n), don't worry about it */
	}
}

/* Constructs a more balanced and slightly less unbalanced sort of tree
void Factor_Tree::construct_even_factor_tree(int r)
{

}
*/

int main()
{
	Factor_Tree *tree = new Factor_Tree(48);
	vector<int> tv = tree->get_factor_tree();
	tree->print_factor_tree();

	return 0;
}
