#include "factor_tree.hpp"

#define NO_FACTOR -1 /* Used to keep track of empty slots in factor tree */

Factor_Tree::Factor_Tree(int r): root(r) 
{
	construct_factor_tree(r);
}

int Factor_Tree::num_nodes(int level)
{
	return pow(2, level);
}

void Factor_Tree::print()
{
	/* Algorithm: Print the level expected number until done or hit -1 which stop printing */
	int level = 0;
	int to_print = num_nodes(level);
	for (int i = 0, size = factor_tree.size(); i < size; ++i)
	{
		int curr = factor_tree[i];
		
		if (curr == NO_FACTOR)
		{
			if (i + 1 != size && factor_tree[i + 1] != NO_FACTOR)
			{
				cout << endl;
			
				level++;
				to_print = num_nodes(level);
			}
		}
		else if (to_print == 0)
		{
			level++;
			to_print = num_nodes(level) - 1;

			cout << endl;
			cout << factor_tree[i] << " ";
		}
		else
		{
			cout << factor_tree[i] << " ";
			to_print--;
		}
	}

	cout << endl;
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
		int curr_factor = (curr != NO_FACTOR ? greatest_factor(curr) : NO_FACTOR);
			
		factor_tree.push_back(curr); /* Add to factor tree */

		/* Prime, no factor */
		if (!curr_factor)
		{
			not_factored.push_back(NO_FACTOR);
			not_factored.push_back(NO_FACTOR);
		}
		/* Not prime or no factor, factor further */
		else if (curr_factor != NO_FACTOR)
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
	for (int x : tv)
		cout << x << " ";
	cout << endl;

	tree->print();

	return 0;
}
