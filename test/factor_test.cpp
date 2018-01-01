/****************************************************
 *
 * Test factor.cpp
 * 
 * Note: Because this is a relatively small project, 
 * 		 a testing framework is overkill. 
 *
 * Author: swolewizard
 *
 *****************************************************/
#include <iostream>
#include "factor.hpp"

using std::endl;

int main()
{
	/* factor of 0 is irrelevant to this project */

	/* factors of 1: 1 */
	vector<int> factor_1 = factor(1);
	vector<int> ans_1 = { 1 };

	if (factor_1.size() != ans_1.size())
	{
    	cout << "Test Failed: factor_1" << endl;
		return -1;
	}

	for (int i = 0; i < factor_1.size(); ++i)
	{
		if (factor_1[i] != ans_1[i])
		{
			cout << "Test Failed: factor_1" << endl;	
			return -1;
		}
	}

	/* factors of 2: 1, 2 */
	vector<int> factor_2 = factor(2);
	vector<int> ans_2 = {1, 2};

	if (factor_2.size() != ans_2.size()) 
	{
		cout << "Test Failed: factor_2" << endl;
		return -1;
	}

	for (int i = 0; i < factor_2.size(); ++i)
	{
		if (factor_2[i] != ans_2[i])
		{
			cout << "Test Failed: factor_2" << endl;
			return -1;
		}
	}
    
	/* factors of 24: 1, 2, 3, 4, 6, 8, 12, 24 */
	vector<int> factor_24 = factor(24);
	vector<int> ans_24 = {1, 2, 3, 4, 6, 8, 12, 24};

	if (factor_24.size() != ans_24.size()) 
	{
		cout << "Test Failed: factor_24" << endl;
		return -1;
	}

	for (int i = 0; i < factor_24.size(); ++i)
	{
		if (factor_24[i] != ans_24[i])
		{
			cout << "Test Failed: factor_24" << endl;
		}
	}
	
	/* factors of 777: 1, 3, 7, 21, 37, 111, 259, 777 */
	vector<int> factor_777 = factor(777);
	vector<int> ans_777 = {1, 3, 7, 21, 37, 111, 259, 777};

	if (factor_777.size() != ans_777.size()) 
	{
		cout << "Test Failed: factor_777" << endl;
		return -1;
	}

	for (int i = 0; i < factor_777.size(); ++i)
	{
		if (factor_777[i] != ans_777[i])
		{
			cout << "Test Failed: factor_777" << endl;
		}
	}	

	cout << greatest_factor(5) << endl;
	cout << greatest_factor(2) << endl;
	vector<int> factor_48 = factor(8);
	for (int x : factor_48)
		cout << x << " ";
	cout << endl;

	return 0;
}
