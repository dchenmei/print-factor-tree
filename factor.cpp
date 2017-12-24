/*****************************************************
 *
 *	Computes all the factors of a positive integer, 
 *	returned in a sorted vector<int>
 *
 *	Author: swolewizard
 *
 *****************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::sort;
using std::cout;

vector<int> factor(unsigned int i)
{	

	if (i == 1)
		return { 1 };

	vector<int> factors;
	for (int a = 1, b = sqrt(i); a <= b; ++a)
    {
		if (i % a == 0)
		{
			factors.push_back(a);
			factors.push_back(i / a);
		}
	}

	sort(factors.begin(), factors.end());

	return factors;
}

