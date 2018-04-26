// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using  namespace std;

int partition(vector<int> &myVec, int left, int right)
{
	int i = left + 1;
	int j = right;
	int key = myVec[left];
	do
	{
		while ((i <= j) && (myVec[i] <= key)) i++;
		while ((i <= j) && (myVec[j] > key)) j--;
		if (i < j)
		{
			swap(myVec[i], myVec[j]);
			i++;
			j--;
		}
	} while (i <= j);
	swap(myVec[left], myVec[j]);
	return j;
}

void quickSort(vector<int> &myVec, int left, int right)
{
	if (left < right)
	{
		int pi = partition(myVec, left, right);
		quickSort(myVec, left, pi - 1);
		quickSort(myVec, pi + 1, right);
	}
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

	quickSort(myVec, 0, myVec.size() - 1);
	for (int i = 0; i < n; i++)
	{
		cout << myVec[i] << endl;
	}
	return 0;
}

