#include<iostream>
using namespace std;

void binarySearch(int arr[],int,int,int);

void exponentialSearch(int arr[],int n,int key)
{
    if(arr[0]==key)
    {
        cout<<"Present "<<"1"<<endl;
        return;
    }
    int i=1;
    while(i<n && arr[i] <= key)
        i *= 2;
    
    binarySearch(arr,i/2,min(i,n-1),key);
    return;
}

void binarySearch(int arr[],int l,int r,int key)
{
    int c=0;

    while(l<=r)
    {
        c++;
        int m = l + (r-l)/2;

        if(arr[m] == key)
        {
            cout<<"Present "<<c<<endl;
            return;
        }

        if(arr[m] < key)
            l = m+1;
        else
            r = m-1;
    }
    cout<<"Not Present "<<c<<endl;
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

        exponentialSearch(arr,n,k);
    }
    return 0;

}