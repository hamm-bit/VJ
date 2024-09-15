#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <any>
#include <optional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long
#define umap unordered_map

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

int n, w;
ll sum = 0, t, curr = 0;
vector<pair<int, ll>> tx;

// =============================================
// ======== Custom functions begin here ========
// =============================================

bool pair_cmp(pair<int, ll> t1, pair<int, ll> t2) {
    return (t1.first < t2.first || (t1.first == t2.first && t1.second < t2.second));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n;
    tx = vector<pair<int, ll>> (n);
    
    for (int i = 0; i < n; i++) {
        cin >> w >> t;
        tx.push_back({w, t});
    }
    sort(tx.begin(), tx.end(), pair_cmp);
    for (pair<int, ll> wt : tx) {
        curr += wt.first;
        sum += (wt.second - curr);
    }
    cout << sum << "\n";

    return 0;
}
