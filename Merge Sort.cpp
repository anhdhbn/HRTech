// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using  namespace std;

void merge(vector<int> &myVec, int left, int mid, int right)
{
	vector<int> temp1(mid - left + 1);
	vector<int> temp2(right - mid);
	int index_array = left;
	for (int i = 0; i < mid - left + 1; i++)
		temp1[i] = myVec[index_array++];

	for (int i = 0; i < right - mid; i++)
		temp2[i] = myVec[index_array++];
	int index_temp1 = 0, index_temp2 = 0;
	index_array = left;

	while (index_temp1 <= mid - left && index_temp2 < right - mid) {

		if (temp1[index_temp1] < temp2[index_temp2]) {

			myVec[index_array] = temp1[index_temp1];
			index_temp1++;
		}
		else {

			myVec[index_array] = temp2[index_temp2];
			index_temp2++;
		}
		index_array++;
	}

	while (index_temp1 <= mid - left) {

		myVec[index_array] = temp1[index_temp1];
		index_array++;
		index_temp1++;
	}

	while (index_temp2 < right - mid) {

		myVec[index_array] = temp2[index_temp2];
		index_array++;
		index_temp2++;
	}
}

void mergeSort(vector<int> &myVec, int left, int right)
{
	int mid = (right + left) / 2;
	if (left < right) {

		mergeSort(myVec, left, mid);
		mergeSort(myVec, mid + 1, right);
		merge(myVec, left, mid, right);
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

	mergeSort(myVec, 0 , myVec.size() - 1);
	for (int i = 0; i < n; i++)
	{
		cout << myVec[i] << endl;
	}
    return 0;
}

