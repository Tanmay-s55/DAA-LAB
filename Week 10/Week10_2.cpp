#include <bits/stdc++.h>
using namespace std;

#define MAX 7
struct job{
    int timetaken;
    int deadline;
    int index;
};

bool cmp(job a1,job a2)
{
    return a1.deadline<a2.deadline;
}

void jobScheduling(job arr[])
{
    sort(arr,arr+MAX,cmp);
    int dead=0;
    vector<int>t;
   for(int i=0;i<MAX;i++)
    {
        int ded=arr[i].timetaken;
        if(ded+dead<=arr[i].deadline)
        {
            dead+=ded;
            t.push_back(arr[i].index);
        }
    }
     cout<<"Max number of tasks: "<<t.size()<<endl;
    cout<<"Selected tasks numbers: ";
    for(auto i: t){
        cout<<i<<" ";
    }
    
}
int main()
{
   struct job j[MAX];
   for(int i=0;i<MAX;i++)
   {
       cin>>j[i].timetaken;
       cin>>j[i].deadline;
       j[i].index=i+1;
   }
   jobScheduling(j);
   return 0;
}
