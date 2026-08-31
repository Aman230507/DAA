//AMIT RAJ 25/DA/013
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj,
         vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, component);
    }
}

vector<vector<int>> findConnectedComponents(
    int V, vector<vector<int>>& adj) {

    vector<bool> visited(V, false);
    vector<vector<int>> components;

    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

int main() {
    int V = 10;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {3, 4},
        {5, 6}, {6, 7}, {7, 8}, {8, 5},
        {9, 9}
    };

    for (auto& e : edges) {
        if (e.first != e.second) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
    }

    cout << "===== Connected Components using DFS ====="
         << endl << endl;

    cout << "Graph has " << V
         << " vertices (0 to " << V - 1 << ")" << endl;

    cout << "Edges: (0-1) (1-2) (2-0) (3-4) "
         << "(5-6) (6-7) (7-8) (8-5)" << endl << endl;

    vector<vector<int>> components =
        findConnectedComponents(V, adj);

    cout << "Number of connected components: "
         << components.size() << endl << endl;

    for (size_t i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": [ ";

        for (int v : components[i])
            cout << v << " ";

        cout << "]" << endl;
    }

    return 0;
}