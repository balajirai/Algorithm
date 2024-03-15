#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

// Bellman-Ford algorithm is designed for directed graphs (can be modified for undirected for non-negative weight)
// Bellman-Ford Algorithm for Directed and Weighted(positive/negative)/Unweighted Graph (General) -> O(E * V)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int source) {
    vector<int> distance(V, INF);
    distance[source] = 0;

    for (int count = 1; count <= V - 1; count++) {
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (distance[u] != INF && distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }

    // detect negative cycle
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (distance[u] != INF && distance[u] + wt < distance[v]) {
            return {-1}; // Negative cycle detected
        }
    }
    return distance;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 4}, {1, 3, 3}, {2, 1, 6}, {3, 2, 2}, {3, 4, 2}, {4, 0, 3}}; // {from, to, weight}
    int source = 0; // Source vertex

    vector<int> distance = bellman_ford(V, edges, source);

    // Output shortest distances from source
        for(int i=0; i<V; i++){
        cout << "Shortest distance from "<< source <<" to " << i << " is : " << distance[i] << endl;
    }

    return 0;
}

/*
input with negative edge : 

{{0, 1, 5}, {0, 2, 4}, {1, 3, 3}, {2, 1, 6}, {3, 2, -2}, {3, 4, 2}, {4, 0, 3}}

*/