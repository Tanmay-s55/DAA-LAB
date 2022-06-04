#include<bits/stdc++.h>
using namespace std;

void dijkstra(int source,int v, vector<pair<int,int>>adj[])
{
    vector<int>vis(v,0);
    vector<int>dist(v,1e9+10);
  	set<pair<int,int>>pq;
   	pq.insert({0,source});
  	dist[source]=0;
  	while(!pq.empty())
   	{
    		auto node=*pq.begin(); 
    		int dis=node.first; cout<<"dis"<<dis<<" "<<endl;
    		int n=node.second; cout<<"node"<<n<<endl;
    		pq.erase(pq.begin());
    	
		if(vis[n])continue;
    			vis[n]=1;
    		for(auto child:adj[n])
    		{
        		int child_n=child.first;
        		int wt=child.second;
        		if(wt+dist[n]<dist[child_n])
        		{
            		dist[child_n]=wt+dist[n];
            		pq.insert({dist[child_n],child_n});
        		}
    		}
  	}

	for(int i=1;i<dist.size();i++)
	{
    	cout<<"Minimum distance from node "<<"1"<<" is"<<dist[i]<<endl;
	}
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>adj[v];
   
    
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
     
    }
    cout<<"Enter Source:";
    int source;
    cin>>source;
   	
    dijkstra(source,v,adj);
    return 0;
}
