#include <bits/stdc++.h>
using namespace std;

// Graph Algorithm for Disjoint Set Union Find

// FIND 
int find(int x, vector<int>& parent) {
    if (x == parent[x]) return x;
    return find(parent[x], parent);
}

// UNION
void unionSet(int x, int z, vector<int>& parent) {
    int x_parent = find(x, parent);
    int z_parent = find(z, parent);

    if (x_parent != z_parent) {
        parent[x_parent] = z_parent;
    }
}

int main() {
    const int N = 10;
    vector<int> parent(N);

    // Initialize each element with its index as the parent
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    // Perform union operations
    unionSet(0, 1, parent);
    unionSet(2, 3, parent);
    unionSet(4, 5, parent);
    unionSet(6, 7, parent);
    unionSet(8, 9, parent);
    unionSet(1, 3, parent); // Combine sets {0, 1, 2, 3}
    unionSet(5, 7, parent); // Combine sets {4, 5, 6, 7}

    // Print the parent of each element after union operations
    cout << "Element: ";
    for (int i = 0; i < N; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Parent:  ";
    for (int i = 0; i < N; i++) {
        cout << find(i, parent) << " ";
    }
    cout << endl;

    return 0;
}