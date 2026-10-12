#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int v, vector<vector<int>>& adj,
         vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v])
        if (!visited[u])
            DFS(u, adj, visited);
}

void BFS(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);
    cout << "DFS: ";
    DFS(start, adj, visited);

    cout << "\nBFS: ";
    BFS(start, adj);

    cout << endl;
    return 0;
}