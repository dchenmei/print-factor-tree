#include "factor_tree.hpp"

#define NO_FACTOR -1 /* Used to keep track of childless nodes in factor tree */

Factor_Tree::Factor_Tree(int r): root(r) 
{
	construct_factor_tree(r);
}

void Factor_Tree::print()
{
	/* Set up intial level and number of nodes to print */
	int level = 0;
	int to_print = num_nodes(level);
	
	/* Algo: For each level, print until the expected number of nodes has reached or hit NO_FACTOR (-1) */
	for (int i = 0, size = factor_tree.size(); i < size; ++i)
	{
		int curr = factor_tree[i];
		
		/* Special case, NO_FACTOR indicates an end of a level */
		if (curr == NO_FACTOR && i + 1 != size && factor_tree[i + 1] != NO_FACTOR)
		{
			cout << endl;
			
			level++;
			to_print = num_nodes(level);
		}
		/* Special case, end of a level */
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

/* Construct an uneven factor tree using greedy algorithm */
void Factor_Tree::construct_factor_tree(int r)
{
	/* Set up first element (root) */
	vector<int> not_factored;
	not_factored.push_back(r); 
	
	/* Algo: For every element, factor until it cannot be factored. Then insert them into the 
     *       the factor tree */
	while (!not_factored.empty())
	{   
		/* Get curr value and calculate greatest factor for curr only if curr is not NO_FACTOR */
		int curr = not_factored[0];
		int curr_factor = (curr != NO_FACTOR ? greatest_factor(curr) : NO_FACTOR);
			
		/* Prime, no factor. Both children are NO_FACTOR */
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
	
		/* curr factored, push into factor_tree and pop from not_factored */
		factor_tree.push_back(curr); 
		not_factored.erase(not_factored.begin()); /* runs O(n), no bottleneck*/
	}
}

/* Calculates the number of expected nodes for a complete binary tree on a certain level */
int Factor_Tree::num_nodes(int level)
{
	/* Factor tree node number is calculated by 2^level */
	return pow(2, level);
}

/* 
void Factor_Tree::construct_even_factor_tree(int r)
{

}
*/
