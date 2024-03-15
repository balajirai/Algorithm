#include <bits/stdc++.h>
using namespace std;

// Prims Algorithm for minimum spanning tree -> O(E * log V)
int spanningTree(int V, vector<int>&parent,  vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});
    
    int sum = 0;
    vector<bool> vis(V, false);
    
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        
        int wt = p.first;
        int node = p.second;
        
        if (vis[node]) continue;
        
        vis[node] = true;
        sum += wt;
        
        for (auto &v : adj[node]) {
            int child = v[0], child_wt = v[1];
            pq.push({child_wt, child});
            parent[child] = node; // Update the parent of the child
        }
    }
    return sum;
}

int main() {
    // Example testcase
    int V = 5;
    vector<vector<int>> adj[V] = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}, {4, 9}},
        {{3, 9}, {2, 7}}
    };

    vector<int>parent(V, -1);

    int min_spanning_tree_cost = spanningTree(V, parent, adj);
    cout << "Cost of minimum spanning tree: " << min_spanning_tree_cost << endl;

    // Print the minimum spanning tree edges
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " -- " << i << endl;
    }

    return 0;
}