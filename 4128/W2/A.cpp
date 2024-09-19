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

int n, k;
int sum = 0, s, f, curr = 0;
vector<pair<int, int>> tx;

// =============================================
// ======== Custom functions begin here ========
// =============================================

bool pair_cmp(pair<int, ll> t1, pair<int, ll> t2) {
    return (t1.second < t2.second || (t1.second == t2.second && t1.first < t2.first));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> k;
    tx = vector<pair<int, int>> (n);
    int min_idx = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        tx[i] = {s, f};
    }
    sort(tx.begin(), tx.end(), pair_cmp);
    for (int i = 0; i < n; i++) {
        if (tx[i].first > tx[min_idx].second) {
            sum++;
            min_idx++;
        } else if (curr < k) {
            curr++;
            sum++;
        }
    }
    cout << sum << "\n";

    return 0;
}
