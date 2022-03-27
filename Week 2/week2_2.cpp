// Given a sorted array of positive integers, design an algorithm and implement it
// using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include<bits/stdc++.h>
using namespace std;

void findInd(int arr[], int n)
{
	int i, l, r;

	for (i = n - 1; i >= 0; i--)
	{
		l = 0, r = i - 1;

		while (l < r)
		{
			if (arr[i] == arr[l] + arr[r])
			{
				cout << l + 1 << " " << r + 1 << " " << i + 1 << endl;
				return;
			}
			else if (arr[i] > arr[l] + arr[r])
				l++;
			else
				r--;
		}
	}
	cout << "No Sequence Found" << endl;
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

		findInd(arr, n);
	}
	return 0;
}