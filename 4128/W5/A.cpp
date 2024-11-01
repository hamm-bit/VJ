#include <bits/stdc++.h>

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
void rDFS(int i)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // ======== Main begins here ========    
    cin >> n >> m;
    vector<vector<int>> AL(n+1, vector<int>(0));
    for (int i = 0; i++<m;) {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    vector<bool> gv(n+1, false);
    vector<bool> tv(n+1, false);
    queue<pair<int, int>> tq;
    vector<int> time(n+1, -1);

    for (int i = 0; i++<n) {
        rDFS(

    // DFS, keep a global array of all visited notes 
    // Also a temporary queue and bool array of visited nodes for backtracking
    // For temporary queue for visited nodes, if a back edge leads back to some in `tv`, terminate
    // Count the temporary s
    return 0;
}
