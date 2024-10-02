#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

#define ll long long
#define ull unsigned long long

// Edit based on given Qs
const int nMOD = (int) 1e9 + 7;
const ll MAX = 5e5 + 5;

// vector<int> DP(MAX);
// vector<vector<int>> DP(MAX, vector<int> MAX);

void arr_print(queue<ll> z, int q = 0) {
    for (;!z.empty(); z.pop()) {
        cout << z.front() << "\n";
    } return;
}

// Credit to Neal Wu's blog (https://codeforces.com/blog/entry/62393)                                                   
// And Sebastiano Vigna for authoring splitmix64
/*
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
*/

// =============================================
// ======== Global variables begin here ========
// =============================================

int n, m, q, a, k, x, y;
vector<array<int, 3>> rds;
array<vector<int>, MAX> adj;
array<int, MAX> ranks{}, pops{}, Ks, As, xs;
vector<pair<int, ll>> parents;
priority_queue<ll> un_sum;

// =================n============================
// ======== Custom functions begin here ========
// =============================================


/*
* Create new sets (leaves)
*/
void make_set(int v) {
    parents[v] = make_pair(v, pops[v]);
}

/*
* UF find a parent, rank increases for every recursion 
*/
int find_set(int v) {
    if (v == parents[v].first)
        return v;
    return find_set(parents[v].first);
}

/*
* UF union two superset (if not the same)
* Grows from maximum rank
*/
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parents[b].first = a;
        parents[b].second += parents[a].second; 
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}


// This is genuinely some of the worst code i've written

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char op;
    queue<ll> ans;

    // ======== Main begins here ========
    cin >> n >> m >> q;
    for (int i = 0; i++ < n;)
        cin >> pops[i];
    cout << "Output ended\n";

    for (int i = 0; i++ < m;) {
        cin >> x >> y;
        array<int, 3> in{{x, y, 0}};
        rds.push_back(in);
    }

    cout << "Output ended\n";

    // Convert the queries to be in reverse order
    for (int i = 0; i++ < q;) {
        if (op == 'D') {
            cin >> k, Ks[i] = k;
            rds[k][2] = 1;
        } else if (op == 'P') {
            cin >> As[i] >> xs[i];
            pops[As[i]] = xs[i];
        } else {
            // debug op
        }
    }

    for (int i = 0; i++ < m;) {
        if (rds[i][2]) continue;
        adj[rds[i][0]].push_back(rds[i][1]);
        adj[rds[i][1]].push_back(rds[i][0]);
    }

    // First BFS to find all regions' pops
    array<bool, MAX> gvisited{};
    queue<int> tobe;
    for (int j = 1; j++ < q;) {
        if (gvisited[j])
            continue;

        array<bool, MAX> visited{};
        make_set(j), tobe.push(j);
        gvisited[j] = 1, visited[j] = 1;

        while (!tobe.empty()) {
            int curr = tobe.front();
            tobe.pop();
            // cout << curr << " ";

            for (int x : adj[j]) {
                if (!visited[x]) {
                    visited[x] = 1, tobe.push(x);
                    union_sets(j, x);
                }
            }
        }
        // cout << curr << "\n";
        // Index maxes of unions into an array, join and 
        int un_max = find_set(j);
        un_sum.push(parents[un_max].second);
    }

    for (int j = q; j > 1; j--) {
        ans.push(un_sum.top());
        if (op == 'D') {
            x = rds[Ks[j]][0], y = rds[Ks[j]][1];
            x = find_set(x), y = find_set(y);
            // CHECK THAT THESE ARE IN SYNC
            union_sets(x, y);
            un_sum.push(parents[x].second);
            un_sum.push(parents[y].second);
        } else if (op == 'P') {
            a = As[j], k = find_set(a);
            // CHECK THAT THESE ARE IN SYNC
            parents[k].second += xs[j] - pops[a];
            un_sum.push(parents[k].second);
        }
    }
    
    arr_print(ans);

    return 0;
}
