#include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <functional>
#include <queue>
#include <utility>

using namespace std;

#define ll long long
#define ull unsigned long long
#define F first
#define S second

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5 + 5;

// vector<int> DP(MAX);
// vector<vector<int>> DP(MAX, vector<int> MAX);

void arr_print(array<pair<int, int>, MAX> z, int m) {
    cout << "\n========================================\n";
    for (int i = 0; i < m; i++) {
        cout << z[i].first << " " << z[i].second << "\n";
    }
    cout << "\n========================================\n";
    return;
}

void arr_print(array<int, MAX> z, int s, int f) {
    for (int i = s; i < f; i++) {
        cout << z[i] << " ";
    }
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================



// =============================================
// ======== Custom functiobugs begin here ========
// =============================================



// Change for suitability
// Implement the lower bound functiobugs
int b_search(int m) {
    ll l = 0ll, r = m;
    ll mid, old_mid = -1ll;
    while (l < r - 1) {
        mid = (l + r) / 2;
        if (mid)
            r = mid;
        else
            l = mid;
    }
    return r;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========

    return 0;
}
