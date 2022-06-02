#include <bits/stdc++.h>
using namespace std;

int count,swaps;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int index = low - 1;
    for (int i = low; i <= high; i++) {
        if (arr[i] < pivot) {
            index++;
            swap(&arr[index], &arr[i]);
            swaps++;
        }
        count++;
    }
    swap(&arr[index + 1], &arr[high]);
    swaps++;
    return (index + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "\n";
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
        count=0,swaps = 0;
        quickSort(arr, 0, n - 1);
        printArray(arr, n);
        cout << "Comparisions: " <<count<< endl;
        cout << "Swaps: " <<swaps << endl;
    }
    return 0;
}