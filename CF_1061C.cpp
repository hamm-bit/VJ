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
