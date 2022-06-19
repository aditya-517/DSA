#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,                       vector<vector<int>> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    for(auto neighbour : adj[node]){
        if(neighbour == parent){
            continue;
        }
        if(!vis[neighbour]){
            dfs(neighbour, node, timer, disc, low, ans, adj, vis);
            
            // update low for node
            low[node] = min(low[node], low[neighbour]);
            
            // check if edge is bridge
            if(low[neighbour] > disc[node]){
                vector<int> bridge;
                bridge.push_back(node);
                bridge.push_back(neighbour);
                ans.push_back(bridge);
            }
        }
        else{
            // back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    // create adj
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;
    
    vector<vector<int>> ans;
    // dfs
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, ans, adj, vis);
        }
    }
    return ans;
}


int main(){
  
  vector<vector<int>> edges = {{0, 1}, {0, 2},{0, 3}, {1, 2}, {3, 4}};
  vector<vector<int>> ans = findBridges(edges, 5, 4);
  
  return 0;
  }