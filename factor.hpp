/*****************************************************
 *
 *	Computes all the factors of a positive integer, 
 *	returned in a sorted vector<int>
 *
 *	Author: swolewizard
 *
 *****************************************************/

#ifndef FACTOR
#define FACTOR

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::sort;
using std::cout;

/* Returns greatest factor (not number itself) */
/* Bonus: if the number is prime, it returns 0! */
int greatest_factor(unsigned int i);
vector<int> factor(unsigned int i);

#endif
