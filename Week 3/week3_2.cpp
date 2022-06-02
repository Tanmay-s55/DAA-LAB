#include <bits/stdc++.h>
using namespace std;

int s,cmp;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    s=0,cmp=0;
    int ind, j;
    for (i = 0; i < n - 1; i++) {
        ind = i;
        for (j = i + 1; j < n; j++) {
            if (arr[ind] > arr[j]) {
                ind = j;
                comp++;
            }
        }
        swap(&arr[ind], &arr[i]);
        s++;
    }
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        selectionSort(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\nComparisions : " << cmp << endl;
        cout << "Shifts : " << s << endl;
    }
    return 0;
}