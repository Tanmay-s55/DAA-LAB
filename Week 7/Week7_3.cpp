#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

int shortestPath(vector<vector<int>> &adj, int src, int dest, int k) {
    int V = adj.size();
    vector<vector<int>> dp(k, vector<int>(V, INF));
    for (int i = 0; i < V; i++)
        dp[0][i] = adj[src][i];
    for (int e = 1; e < k; e++) {
        for (int i = 0; i < V; i++) {
            if (dp[e - 1][i] != INF) {
                for (int j = 0; j < V; j++) {
                    if (adj[i][j] != INF) {
                        dp[e][j] = min(dp[e][j], dp[e - 1][i] + adj[i][j]);
                    }
                }
            }
        }
    }

    return dp[k - 1][dest];
}

int main() {
    int V;
    cin >> V;
    vector<vector<int>> adj(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adj[i][j];
            adj[i][j] = (adj[i][j] == 0) ? INF : adj[i][j];
        }
    }
    int src, dest, k;
    cin >> src >> dest;
    cin >> k;
    int dist = shortestPath(adj, src - 1, dest - 1, k);
    cout << "Weight of shortest path from (" << src << ", " << dest << ") with " << k << " edges: " << dist << endl;
    return 0;
}