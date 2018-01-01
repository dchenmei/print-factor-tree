/*****************************************************
 *
 * Helper functions for computing factors
 *
 * Author: swolewizard
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

/* Returns greatest factor of i (positive integer), not including itself */
int greatest_factor(int i);

/* Return a sorted list containing factors of i (positive integer), including one and i itself */
vector<int> factor(int i);

#endif
