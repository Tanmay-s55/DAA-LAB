#include <bits/stdc++.h>
using namespace std;

#define MAX 6
struct Activity{
    int start;
    int finish;
    Activity()
    {
        start=0;
        finish=0;
    }
};
bool cmp(Activity a1,Activity a2)
{
    return a1.finish<a2.finish;
}
void ActivitySelection(Activity arr[],int n)
{
    sort(arr,arr+n,cmp);
    vector<pair<int,int>>v;
    int i=0,prev=0,count=1;
    v.push_back({arr[i].start,arr[i].finish});
    for(int j=1;j<n;j++)
    {
        if(arr[j].start>=arr[prev].finish)
        {
            // cout<<arr[j].start<<" "<<arr[j].finish<<endl;
            v.push_back({arr[j].start,arr[j].finish});
            count++;
            prev=j;
        }
    }
    cout<<"No. of non conflicting activities: "<<count<<endl;
    cout<<"list of non conflicting activities: ";
    for(auto &it:v)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main()
{
    struct Activity ac[MAX];
    for(int i=0;i<MAX;i++)
    {
        cin>>ac[i].start;
        cin>>ac[i].finish;
    }
    ActivitySelection(ac,MAX);
    return 0;
}
