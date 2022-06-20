// To find Articulation Points in a graph 
// Tarjan's Algo

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<int> &ap, unordered_map<int, list<int>> &adj, int &timer){

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto neighbour : adj[node]){
        if(neighbour == parent)
        continue;

        if(!vis[neighbour]){
            dfs(neighbour, node, disc, low, vis, ap, adj, timer);

            low[node] = min(low[node], low[neighbour]);

            // check for AP
            if((low[neighbour] >= disc[node]) && parent != -1){
                ap[node] = 1;
            }
            child++;
        }
        else{
            // backedge
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    if(parent == -1 && child > 1){
        ap[node] = 1;
    }
}

int main()
{   int n = 5, e=5;
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    // adj list
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0; 
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, false);
    vector<int> ap(n, 0);

    for(int i=0; i<n; i++){
        if(!vis[i])
        dfs(i, -1, disc, low, vis, ap, adj, timer);
    }

    for(int i=0; i<n; i++)
    if(ap[i]!=0)
    cout<<i<<" ";

    cout<<endl;

    return 0;
}