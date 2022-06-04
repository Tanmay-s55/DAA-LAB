#include <bits/stdc++.h>
using namespace std;

double findmedian(int arr[],int n)
{
    double ans;
    if(n%2==0)
    {
      ans=double(arr[n/2]);
    }
    else{
        ans= (double)(arr[(n-1)/2] + arr[n/2])/2.0;
    }
    return ans;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   int res=arr[0],count=1;
   for(int i=1;i<n;i++)
   {
       if(arr[i]==res)count++;
       else{
            count--;
           if(count==0)
           {
               res=arr[i];
               count=1;
           }
          
       }
   }
  count=0;
  for(int i=0;i<n;i++)
  {
      if(arr[i]==res)count++;
  }
  if(count>n/2)cout<<"yes"<<endl;
  else cout<<"No"<<endl;
 cout<<"Median ="<< findmedian(arr,n);
    return 0;
}
