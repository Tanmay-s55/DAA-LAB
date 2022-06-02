#include <bits/stdc++.h>
using namespace std;

int cmp=0;

int merge(int arr[], int temp[], int low, int mid, int high);
int mergeSortUtil(int arr[], int temp[], int low, int high);

int mergeSort(int arr[], int n) {
    int temp[n];
    return mergeSortUtil(arr, temp, 0, n - 1);
}

int mergeSortUtil(int arr[], int temp[], int low, int high) {
    int mid, inv = 0;
    if (high > low) {
        mid = low + (high - low) / 2;
        count_inv += mergeSortUtil(arr, temp, low, mid);
        count_inv += mergeSortUtil(arr, temp, mid + 1, high);

        inv += merge(arr, temp, low, mid + 1, high);
    }
    return inv;
}

int merge(int arr[], int temp[], int low, int mid, int high) {
    int i, j, k;
    i = k = low;
    j = mid;
    int inv = 0;

    while ((i <= mid - 1) and (j <= high)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (mid - i);
        }
        cmp++;
    }

    while ((i <= mid - 1))
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
    return inv;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cmp = 0;
        int inv = mergeSort(arr, n);
        printArray(arr, n);
        cout << "Comparisions: " << cmp << endl;
        cout << "Inversions: " << inv << endl;
    }
    return 0;
}