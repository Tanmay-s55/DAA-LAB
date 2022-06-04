#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    int dist[v][v];
    
    for(int i=1;i<=v;i++)
    {
       for(int j=1;j<=v;j++)
       {
           if(i==j)dist[i][j]=0;
           else dist[i][j]=1e6+10;
       }
    }
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v]=wt;
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int k=1;k<=v;k++)
    {
        for(int j=1;j<=v;j++)
        {
            for(int i=1;i<=v;i++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
