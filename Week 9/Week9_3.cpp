#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int res[n];
    for(int i=0;i<n;i++)
    {
       cin>>res[i];
    }

    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(res[i]);
    }

    int ans=0;
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int temp=a+b;
        ans+=a+b;
        pq.push(temp);
    }
   cout<<"cost = "<<ans;
   return 0;
}
