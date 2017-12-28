/*****************************************************
 *
 *	Computes all the factors of a positive integer, 
 *	returned in a sorted vector<int>
 *
 *	Author: swolewizard
 *
 *****************************************************/

#include "factor.hpp"

/* Returns greatest factor (not number itself) */
/* Bonus: if the number is prime, it returns 0! */
int greatest_factor(unsigned int i)
{
	if (i == 1)
		return { 1 };
	
	int greatest_factor;
	for (int a = 2, b = sqrt(i); a <= b; ++a)
	{
		/* Found greatest factor */
		if (i % a == 0)
		{
	 		greatest_factor = i / a;
			break;
		}
	}
	
	return greatest_factor;
}

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
