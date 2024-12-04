#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <any>
#include <optional>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5 + 5;

// vector<int> DP(MAX);
// vector<vector<int>> DP(MAX, vector<int> MAX);

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// Change for suitability
/*
int b_search(int i) {
    ll l = 0ll, r = DP.size();
    ll mid = l + (r - l) / 2, old_mid = -1ll;
    while (l <= r) {
        if (DP[mid] == i || mid == old_mid)
            break;
        else if (DP[mid] > i)
            r = mid;
        else
            l = mid;
    }
    return mid;
}
*/

// =============================================
// ======== Global variables begin here ========
// =============================================



// =============================================
// ======== Custom functions begin here ========
// =============================================

// UPDATE: check the priority of the last character everytime.
// Since the number of `+` is bounded by 26, its constant
inline int tot_str(vector<int> freq, int i) {
    int sum = 0;
    for (int j = 0; j < i; j++)
        sum += freq[j];
    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    string in, t, u;
    cin >> in;
    int n = in.length();
    vector<int> freq(26);
    for (int i = 0; i < n; i++)
        freq[in[i] - 'a']++;

    // backward sweep and collect the chars
    // at the same time decide if to draw from the final char.
    // the lexicographical order of a substring is minimized
    // when they are emptied out from the frequency table in order.
    //
    // UPDATE: remove condition for 'a'
    for (char c : in) {
        t += c;
        freq[c - 'a']--;
        while (!(t.empty()) && tot_str(freq, t.back() - 'a') == 0) {
            // greedy avail
            u += t.back();
            t.pop_back();
        }
    }
    cout << u << "\n";
    return 0;
}
