#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5;

// Floyd-Warshall algorithm (directed graph)
void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;

    // Floyd Warshell
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
            }
        }
    }

    // Print the shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }
    cout << "No negative cycle detected." << endl;
}

int main() {
    // Number of vertices in the graph
    int n = 4;

    // Adjacency matrix of the graph
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}