#include <bits/stdc++.h>
#include <utility>

using namespace std;

#define ll long long
#define F first
#define S second

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
const int nMAX = 1e5;
const int mMAX = 3e5;

void arr_print(array<array<int, nMAX>, MAX> z, int m) {
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


int n, m, a, b;
vector<vector<int>> AL(nMAX, vector<int>(0));
vector<int> vist(n+1, -1);


void tarjanDFS(int u, int& t, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack, vector<vector<int>>& adj, vector<vector<int>>& sccs) {
    disc[u] = low[u] = ++t;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, t, disc, low, st, inStack, adj, sccs);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        vector<int> scc;
        int v;
        do {
            v = st.top();
            st.pop();
            inStack[v] = false;
            scc.push_back(v);
        } while (v != u);
        sccs.push_back(scc);
    }
}

vector<vector<int>> findSCCs(int V, vector<vector<int>>& adj) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> st;
    vector<vector<int>> sccs;
    int t = 0;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1) {
            tarjanDFS(i, t, disc, low, st, inStack, adj, sccs);
        }
    }

    return sccs;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // ======== Main begins here ========    
    cin >> n >> m;
    for (int i=0; i++<m;) {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    vector<bool> gv(n+1, false);
    vector<bool> tv(n+1, false);
    queue<pair<int, int>> tq;

    for (int i=0; i++<n;) {
        if (!gv[i]) {
            tarjanDFS(i, -1, tv, tq, 0);
        }
    }

    // DFS, keep a global array of all visited notes 
    // Also a temporary queue and bool array of visited nodes for backtracking
    // For temporary queue for visited nodes, if a back edge leads back to some in `tv`, terminate
    // Count the temporary s
    return 0;
}
