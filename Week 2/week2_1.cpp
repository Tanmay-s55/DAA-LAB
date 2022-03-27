#include<bits/stdc++.h>
#include<vector>
using namespace std;

int bSearch(int arr[], int l, int r, int k)
{
	if (r < l)
		return -1;

	int m = l + ((r - l) / 2);

	if (arr[m] == k)
		return m;
	else if (arr[m] < k)
		return bSearch(arr, m + 1, r, k);
	else
		return bSearch(arr, l, m - 1, k);

}

int countFreq(int arr[], int l, int r, int key)
{
	int ind = bSearch(arr, l, r, key);

	if (ind == -1)
		return 0;

	int c = 1, li = ind - 1, ri = ind + 1;
	while (li >= 0 && arr[li] == key)
		c++, li--;

	while (ri < r && arr[ri] == key)
		c++, ri++;

	return c;
}

int main()
{
	int n, k;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> k;

	int f = countFreq(arr, 0, n, k);
	cout << k << " - " << f << endl;
}