// Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K.

//using hashing. Time complexity:- O(n)

#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int findPairs(int arr[], int n, int k)
{
	int c = 0;

	bool hashMap[MAX] = {false};

	for (int i = 0; i < n; i++)
		hashMap[arr[i]] = true;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] - k >= 0 && hashMap[arr[i] - k])
			c++;
		if (arr[i] + k < MAX && hashMap[arr[i] + k])
			c++;
		hashMap[arr[i]] = false;
	}
	return c;
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

		int count = findPairs(arr, n, k);
		cout << count << endl;
	}
	return 0;
}