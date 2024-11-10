#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
const int nMAX = 19;

void arr_print(vector<vector<int>> z) {
    cout << "\n========================================\n";
    for (auto x : z) {
        for (int a : x)
            cout << a << " ";
        cout << "\n";
    } cout << "\n";
}

void arr_print(array<int, MAX> z, int s, int f) {                                                                       
    for (int i = s; i < f; i++)
        cout << z[i] << " ";                                                                                            
}

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[v] = true;
    for (int neighbor : adj[v])
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, finishStack);
    finishStack.push(v);
}

void reverseGraph(vector<vector<int>>& adj, vector<vector<int>>& revAdj) {
    int V = adj.size();
    for (int v = 0; v < V; ++v)
        for (int neighbor : adj[v])
            revAdj[neighbor].push_back(v);
}

void topoVerif(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : adj[v])
        if (!visited[neighbor])
            topoVerif(neighbor, adj, visited);
}

bool isUniversalSink(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    stack<int> finishStack;

    for (int i = 0; i < V; ++i)
        if (!visited[i])
            dfs(i, adj, visited, finishStack);

    vector<vector<int>> revAdj(V);
    reverseGraph(adj, revAdj);

    fill(visited.begin(), visited.end(), false);
    topoVerif(0, revAdj, visited);
    for (bool reachable : visited)
        if (!reachable) return false; 

    return true; 
}

int n, a, b;

int main() {
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[i][0] = a-1, adj[i][1] = b-1;
    }

    if (isUniversalSink(adj))
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}

