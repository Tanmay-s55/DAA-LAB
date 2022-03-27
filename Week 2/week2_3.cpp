// Given an array of nonnegative integers, design an algorithm and a
// program to count the number of pairs of integers such that their
// difference is equal to a given key, K.

//method 1 sorting array using sorting like merge sort O(nlogn) & then doing
//binary search O(logn) for arr[i] + k.

#include<bits/stdc++.h>
using namespace std;

int bSearch(int arr[], int low, int high, int key)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			return bSearch(arr, low + 1, high, key);
		else
			return bSearch(arr, low, high - 1, key);
	}
	return -1;
}

int countPairs(int arr[], int n, int key)
{
	int cnt = 0;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		if (bSearch(arr, i + 1, n - 1, arr[i] + key) != -1)
			cnt++;
	return cnt;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n;

		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> k;

		int c = countPairs(arr, n, k);
		cout << c << endl;
	}
	return 0;
}