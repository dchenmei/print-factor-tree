#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/****************************************************
 *
 *	Computes all the factors of a positive integer
 *
 *****************************************************/

using std::vector;
using std::sort;
using std::cout;

std::vector<int> factor(int i)
{	
	vector<int> factors;
	for (int a = 1, b = sqrt(i); a <= b; ++a)
    {
		if (i % a == 0)
		{
			factors.push_back(a);
			factors.push_back(i / a);
		}
	}

	return factors;
}

int main()
{
	std::vector<int> v = factor(24);
	sort(v.begin(), v.end());

	for (int x : v)
		cout << x << " ";

	return 0;
}


