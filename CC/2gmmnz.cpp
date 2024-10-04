#include <algorithm>
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
vector<vector<int>> adj;
array<int, MAX> ranks{}, pops{}, Ks, As, xs;
array<pair<int, ll>, MAX> parents;
multiset<ll, greater<ll>> un_sum;


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
void union_sets(int l, int r) {
    l = find_set(l);
    r = find_set(r);
    if (l != r) {
        if (ranks[l] < ranks[r])
            swap(l, r);
        parents[r].first = l;
        parents[l].second += parents[r].second; 
        if (ranks[l] == ranks[r])
            ranks[l]++;
    }
}


// This is genuinely some of the worst code i've written

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char op;
    queue<ll> ans;
    rds.push_back({0, 0, 1});

    // ======== Main begins here ========
    cin >> n >> m >> q;
    for (int i = 0; i++ < n;)
        cin >> pops[i];
    adj.resize(n + 2);
    adj[0].push_back(0);

    for (int i = 0; i++ < m;) {
        cin >> x >> y;
        rds.push_back({x, y, 0});
    }

    // Convert the queries to be in reverse order
    int prev_pop = -1;
    for (int i = 0; i++ < q;) {
        cin >> op;
        if (op == 'D') {
            cin >> k, Ks[i] = k;
            rds[k][2] = 1;
        } else if (op == 'P') {
            cin >> As[i] >> x;
            xs[i] = pops[As[i]];
            pops[As[i]] = x;
        } else {
            // debug op
        }
    }

    /*
    for (auto arr : rds) {
        for (int num : arr)
            cout << num << " ";
        cout << "\n";
    }
    */
    
    // cout << adj[n-1].size();

    for (int i = 0; i++ < m;) {
        if (rds[i][2]) 
            continue;
        adj[rds[i][0]].push_back(rds[i][1]);
        cout << adj[rds[i][0]].front() << " ";
        adj[rds[i][1]].push_back(rds[i][0]);
        cout << adj[rds[i][1]].front() << "\n";
    }

    // ==========================================
    for (int i = 0, mm = 0; i++ < n && mm < m;) {
        // cout << (sizeof(adj[i]));
        for (int j = 0; j++ < adj[i].size();mm++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    // ==========================================

    // First BFS to find all regions' pops
    array<bool, MAX> gvisited{};
    queue<int> tobe;
    for (int j = 0; j++ < n;) {
        if (gvisited[j])
            continue;

        array<bool, MAX> visited{};
        make_set(j), tobe.push(j);
        visited[j] = 1, gvisited[j] = 1;

        for (int curr = tobe.front(); !tobe.empty(); tobe.pop(), curr = tobe.front()) {
            // curr src node printer
            cout << curr << " ";
            if (adj[curr].size() == 0)
                continue;
            for (int nd : adj[curr]) {
                if (!visited[nd]) {
                    make_set(nd), tobe.push(nd);
                    visited[nd] = 1, gvisited[nd] = 1;
                    union_sets(curr, nd);
                }
            }
        }
        cout << "\n";
        // Index maxes of unions into an array, join and 
        int un_max = find_set(j);
        un_sum.insert(parents[un_max].second);
    }

    // parent printer
    for (int i = 0; i++ < n;)
        cout << parents[i].first << " " << parents[i].second << "\n";
    cout << "\n";

    // un_sum printer
    /*
    for (int i = un_sum.top(); !un_sum.empty(); un_sum.pop(), i = un_sum.top())
        cout << i << " ";
    cout << "\n";
    */

    for (int j = q; j > 0; j--) {
        cout << *un_sum.begin() << " ";
        ans.push(*un_sum.begin());
        if (op == 'D') {
            x = rds[Ks[j]][0], y = rds[Ks[j]][1];
            x = find_set(x), y = find_set(y);
            if (x == y) 
                continue;
            un_sum.erase(un_sum.find(parents[x].second));
            un_sum.erase(un_sum.find(parents[y].second));
            // CHECK THAT THESE ARE IN SYNC
            union_sets(x, y);
            if (ranks[x] < ranks[y])
                swap(x, y);
            // multiset erases all instances of a value if remove by value
            // so here we use erase by iterator to remove first
            un_sum.insert(parents[x].second);
        } else if (op == 'P') {
            a = As[j], k = find_set(a);
            // CHECK THAT THESE ARE IN SYNC
            //
            // TODO: IT IS NOT CURRENTLY IN SYNC
            // USE 0 IDX OF Ks ARR FOR THE ORIGINAL POP
            un_sum.erase(un_sum.find(parents[k].second));
            parents[k].second += xs[j] - pops[a];
            un_sum.insert(parents[k].second);
            pops[a] = Ks[j];
        }
        cout << "\n";
    }

    for (ll i : un_sum)
        cout << i << " ";
    cout << "\n";
    
    arr_print(ans);

    return 0;
}
