#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,key;
        cin>>n;
    
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>key;
    
        int j = sqrt(n);
        int low=0,high=j,c=0;
    
        while(arr[high] <= key && high<n)
        {
            low = high;
            high += j;
        
            if(high > n-1)
                high = n; //if high exceeds upper bound then set it to maximum
        }
    
        for(int i=low;i<high;i++)
        { 
            c++;
            if(arr[i] == key)
            {
                cout<<"Present "<<c<<endl;
                return 0;
            }
        }
        cout<<"Not Present"<<c<<endl;
    }
    return 0;
}