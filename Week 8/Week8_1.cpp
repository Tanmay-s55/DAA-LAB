#include<bits/stdc++.h>
using namespace std;
void prims(vector<pair<int,int>>adj[],int v)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int src=0;
    vector<int>key(v,1e6+10);
    vector<int>parent(v,-1);
    vector<bool>vis(v,false);
    pq.push({0,src});
    key[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto x:adj[u])
        {
            int v=x.first;
            int weight=x.second;
            if(!vis[v] && key[v]>weight)
            {
                key[v]=weight;
                pq.push({key[v],v});
                parent[v]=u;
            }
        }
    }
    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    prims(adj,n);
}
