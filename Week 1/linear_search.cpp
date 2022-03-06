#include<iostream>
using namespace std;

/* Given an array of nonnegative integers, design a linear algorithm and
implement it using a program to find whether a given key element is present in the array or
not. Also, find the total number of comparisons for each input case. (Time Complexity =
O(n), where n is the size of input).
For this problem you are free to choose programming language, no. of test cases, input and
output format.
If you feel ambitious about problem solving, keep the input inside a text file, read that using a
program to generate the output in another file.
Hint - You can take the first line as n, no. of test cases and after that n lines containing
various numbers of elements where each line represents an array. */
void lsearch(int *arr,int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(*(arr+i) == key)
        {
            cout<<"Present "<<i<<endl;
            return;
        }
    }
    cout<<"Not Present "<<i-1<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        cin>>k;

        lsearch(arr,n,k);
    }
    return 0;
}