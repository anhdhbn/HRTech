// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using  namespace std;

int getMaxValue(vector<int> myVec)
{
	int maxCurr = myVec[0];
	for (int i = 1; i < myVec.size(); i++)
	{
		if (myVec[i] > maxCurr)
		{
			maxCurr = myVec[i];
		}
	}
	return maxCurr;
}

int getLengthMax(vector<int> myVec)
{
	int valueMax = getMaxValue(myVec);
	return std::to_string(valueMax).length();
}

void countSort(vector<int> &myVec, int exp)
{
	int n = myVec.size();
	vector<int> output(n);
	vector<int> count(10, 0);

	for (int i = 0; i < n; i++)
		count[(myVec[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(myVec[i] / exp) % 10] - 1] = myVec[i];
		count[(myVec[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		myVec[i] = output[i];
}

void radixSort(vector<int> &myVec)
{
	int m = getMaxValue(myVec);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(myVec, exp);
}

int main()
{
	int n;
	cin >> n;
	vector<int> myVec(n, INT16_MIN);
	for (int i = 0; i < n; i++)
	{
		cin >> myVec[i];
	}

	radixSort(myVec);
	for (int i = 0; i < n; i++)
	{
		cout << myVec[i] << endl;
	}
	return 0;
}

