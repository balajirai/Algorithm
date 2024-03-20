#include <bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm 

// DSU Code Starts -----------------------------
vector<int> parent;
vector<int> Rank;

int find (int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    
    if (x_parent == y_parent) return;
    if(Rank[x_parent] > Rank[y_parent]) {
        parent[y_parent] = x_parent;
    } 
    else if(Rank[x_parent] < Rank[y_parent]) {
        parent[x_parent] = y_parent;
    } 
    else {
        parent[x_parent] = y_parent;
        Rank[y_parent]++;
    }
}

// DSU Code Ends -------------------------------


// Kruskal's Algorithm
int kruskal(vector<vector<int>> &edges) {
    int sum = 0;
    for(auto &temp : edges) {
        
        int u = temp[0];
        int v = temp[1];
        int wt = temp[2];
        
        int parent_u = find(u);
        int parent_v = find(v);
        
        if(parent_u != parent_v) {
            Union(u, v);
            sum += wt;
        }
        
    }
    return sum;
}

int spanningTree(int V, vector<vector<int>> adj[]){
    parent.resize(V);
    Rank.resize(V, 0);
    for(int i = 0; i<V; i++) parent[i] = i;
    
    vector<vector<int>>edges;
    for(int u=0; u < V; u++){
        for(auto child:adj[u]){
            int v = child[0], wt = child[1];
            edges.push_back({u, v, wt});
        }
    }
    
    // comparator for sorting edges
    auto cmp = [&](auto &v1, auto &v2){
        return v1[2] < v2[2];
    };
    
    // sort edges based on wt (ascending order)
    sort(edges.begin(), edges.end(), cmp);
    
    return kruskal(edges);
}

int main() {
    // Test Case
    int V = 5;
    vector<vector<int>> adj[V] = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}, {4, 9}},
        {{3, 9}, {2, 7}}
    };

    int minCost = spanningTree(V, adj);
    cout << "Minimum Cost Spanning Tree: " << minCost << endl;

    return 0;
}