#include<bits/stdc++.h>
using namespace std;

void findmax(vector<char>&v,int &max,char ch)
{
   vector<int>count(256,0);
 
   for(int i=0;i<v.size();i++)
   {
       int a=v[i];
      
       count[a]++;
       if(max<count[a])
       {
           max=count[a];
           ch=a;
           
       }
   }
  
 }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,max=0;
        char ch;
        cin>>n;
        vector<char>v;
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            v.push_back(c);
        }
          findmax(v,max,ch);
          if(max<=1)cout<<"No duplicate found!"<<endl;
          else cout<<ch<<" "<<max<<endl;
    }
}