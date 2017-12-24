/*********************************************
 * Factor tree root class, contains the fundamental
 * features without a construction method.
 *
 * Author: swolewizard
 *
 * *******************************************/

#include <iostream>

using std::cout;

class Factor_Tree
{
  public:
	
	Factor_Tree(int r, vector<int> f)
	{
		root = r;
		f = factor_tree;
	}

	void print_factor_tree()
	{
	

	}

	int get_root()
		return root;

	void set_root(int i)
		root = i;

  private:
    int root;
	vector<int> factor_tree;
};
