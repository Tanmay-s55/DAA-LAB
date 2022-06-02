//Given an unsorted array of integers, design an algorithm and a program to sort the
//array using insertion sort. Your program should be able to find number of comparisons
//and shifts ( shifts total number of times the array elements are shifted from their
//place) required for sorting the array.

// For each test case T, there will be three output lines.
// 	First line will give the sorted array.
// 	Second line will give total number of comparisons.
// 	Third line will give total number of shift operations required.

#include<bits/stdc++.h>
using namespace std;

void sortArray(int *p, int n)
{
	int c = 0, s = 0;
	for (int i = 1; i < n; i++)
	{
		int current = *(p + i);
		int j = i - 1;
		while (*(p + j) > current && j >= 0)
		{
			*(p + j + 1) = *(p + j);
			c++, s++, j--;
		}
		*(p + j + 1) = current;
		s++;
	}

	for (int i = 0; i < n; i++)
		cout << *(p + i) << " ";
	cout << "\nShifts: " << s << "\nComparisons: " << c << endl;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sortArray(arr, n);
	}
	return 0;
}