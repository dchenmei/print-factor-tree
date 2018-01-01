/*****************************************************
 *
 * Implementation file for factor.hpp functions 
 *
 *Author: swolewizard
 *
 *****************************************************/

#include "factor.hpp"

/* Returns greatest factor of integer i that is not itself */
int greatest_factor(int i)
{
	/* Default is 0, which works with prime numbers such as 1, 2 and 3 */
	int greatest_factor = 0;

	/* Traverse from a = 2 to sqrt(i) and find number that can divide i evenly. No need to traverse
     * up to i because factors come in pairs. A big factor can be calculated from a small factor */
	for (int a = 2, b = sqrt(i); a <= b; ++a)
	{
		/* If a can divide i evenly, it is a factor of i */
		if (i % a == 0)
		{
			/* The corresponding factor of a small factor is a big factor */
	 		greatest_factor = i / a;
			break;
		}
	}
	
	return greatest_factor;
}

/* Returns a sorted list containing factors of i, including itself and one */
vector<int> factor(int i)
{	
	/* Special case, one only have one factor */
	if (i == 1)
		return { 1 };

	vector<int> factors;
	/* Traverse from a = 2 to sqrt(i) and find numbers that can divide 1 evenly. No need to traverse up to 
     * i because factors come in pairs */
	for (int a = 1, b = sqrt(i); a <= b; ++a)
    {
		/* If a can divide i evenly, it is a factor of i */
		if (i % a == 0)
		{
			factors.push_back(a);
			factors.push_back(i / a);
		}
	}

	sort(factors.begin(), factors.end());

	return factors;
}
