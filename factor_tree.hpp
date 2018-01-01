/*********************************************
 * Defines a factor tree and related methods 
 *
 * Author: swolewizard
 *
 * *******************************************/

#ifndef FACTOR_TREE_HPP
#define FACTOR_TREE_HPP

#include "factor.hpp" /* greatest_factor() */
#include <vector>
#include <cmath>

using std::vector;

class Factor_Tree
{
  public:

	/* Constructs a factor tree given root r (positive integer) */
	Factor_Tree(int r);

	/* Prints non-formatted factor tree */
	void print();

	int get_root();
	vector<int> get_factor_tree();
	void set_root(int i);

  private:
	
	/* Helper functions */
    void construct_factor_tree(int r);
	int num_nodes(int l);
	// void construct_even_factor_tree(int r);
	
	/* Member variables */
    int root;
	vector<int> factor_tree;
};

#endif 
