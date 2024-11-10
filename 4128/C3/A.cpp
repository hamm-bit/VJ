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

void arr_print(vector<int> z) {                                                                       
    for (int a : z)
        cout << a << " ";
    cout << "\n";
}


vector<bool> visited;

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

// components -- the strongy connected components in G
// adj_cond -- adjacency list of G^SCC (by root vertices)
void SCC(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond,
                                  vector<int> &vroots) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(begin(component), end(component));
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);

    vroots = roots;
}

void reverseGraph(vector<vector<int>>& adj, vector<int> roots, vector<vector<int>>& revAdj) {
    int V = adj.size();
    vector<bool> rvisited(V, false);
    revAdj.resize(V);
    // cout << V << "\n";
    for (int v = 0; v < V; ++v) {
        int v_root = roots[v];
        if (rvisited[v_root]) continue;
        for (int neighbor : adj[v_root]) 
            revAdj[neighbor].push_back(v_root);
        rvisited[v_root] = true;
    }
}

int n, a, b;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n;
    vector<vector<int>> adj = vector(n, vector<int>(2));
    vector<vector<int>> cmpnt{}, cmpnt_adj{}, rev_adj{};
    vector<int> vroots{};
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[i][0] = a-1, adj[i][1] = b-1;
    }
    // cout << cmpnt.size() << "\n";
    SCC(adj, cmpnt, cmpnt_adj, vroots);
    // cout << cmpnt.size() << "\n";
    // cout << cmpnt_adj.size() << "\n";
    // cout << vroots.size() << "\n";
    // arr_print(cmpnt);
    // arr_print(cmpnt_adj);
    // arr_print(vroots);
    reverseGraph(cmpnt_adj, vroots, rev_adj);
    // arr_print(rev_adj);

    int v0 = vroots[0];
    int num_empty = rev_adj[v0].size();
    // cout << num_empty << "\n";
    // no incoming edge to 0
    if (num_empty != 0) return cout << "No\n", 0;
    num_empty = cmpnt_adj[v0].size();
    // cout << num_empty << "\n";
    // no multiple outgoing edge from 0
    if (num_empty > 1) return cout << "No\n", 0;

    num_empty = 0;
    vector<bool> rvisited(n, false);
    rvisited[v0] = true;
    // Find if there exist other maximal orders
    for (int v = 0; v < n; v++) {
        int v_root = vroots[v];
        if (rvisited[v_root]) continue;
        if (rev_adj[v_root].size() == 0)
            return cout << "No\n", 0;
        rvisited[v_root] = true;
    }

    num_empty = 0;
    // number of bridges = number of SCC - 1
    for (auto bridge : cmpnt_adj) {
        for (int v : bridge)
            num_empty++;
    }


    // cout << num_empty << "\n";
    if (num_empty + 1 == cmpnt.size())
        return cout << "Yes\n", 0;
    return cout << "No\n", 0;
}
