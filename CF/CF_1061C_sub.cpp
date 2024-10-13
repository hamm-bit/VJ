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
const int nMOD = (int) 1e9 + 7;
const ll MAX = 1e5 + 5;
const int aMAX = 1e6 + 5;

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

// Credit to Neal Wu's blog (https://codeforces.com/blog/entry/62393)
// And Sebastiano Vigna for authoring splitmix64
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

// =============================================
// ======== Global variables begin here ========
// =============================================

int n, a;
int as[MAX], DP[aMAX];

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
    cin >> n;
    as[0] = 0;
    for (int i = 0; i < n; i++) cin >> as[i];

    // DP relations
    // We denote the beginningo f a subsequence as the major index
    // Since a sequence of length 1 is always valid.
    //
    // Then for each iteration, for each valid continuation we plus one.
    // This is npt however viable, since to "DP" we need to be able to share computed values
    // But a buttom-up approach cannnot utilize that.
    // At the same time it is not possible to top-down because we need to maintain the order of the sequence
    // Without knowing the starting point we cannot do so.
    //
    // Therefore, we would alter our DP scheme to enable top-down and memoization
    // By encoding the major index as the ending index, and the minor index as the deisred length
    // 
    // And we have recurrence of,
    
    /*
     *  # Note i is 1-indexed
     *  if (as[i] % j)
     *      DP[i][j] = DP[i-1][j] + DP[i-1][j-1]
     *  else
     *      DP[i][j] = DP[i-1][j]
     */

    // It is noticeable however a 1e5 x 1e6 array will defnintely exceed mem limit.
    // We would seek to reduce this to 1-D
    // Since we could find factors of a number in O(sqrt(n)) time, we could abandon
    // the [i] index and only encode the array based on its length.
    //
    
    for (;n--;) {
        for (int j = 1; j * j <= as[n]; j++) {
            if (as[n] % j) continue;
            DP[j] = (DP[j] + 1 + DP[j + 1]) % nMOD;
            if (j == as[n] / j) continue;
            DP[as[n] / j] = (DP[as[n] / j] + 1 + DP[as[n] / j + 1]) % nMOD;
        }
    }
    cout << as[1] << "\n";
    return 0;
}
