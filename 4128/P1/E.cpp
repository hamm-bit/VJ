#include <iostream>
#include <fstream>
#include <string>
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

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// ================================================
// ========= string algorithms (growing) ==========
// ================================================

// Converts a string of length n to an n-length array of indices
// where z[i] indicates the current position of this character
// in the prefix of s
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        // arr_print(pi);
    }
    return pi;
}


// ======== NOTES ========
/*  Subproblem:
 *
 *  We can construct the total number of prefixes included at each i
 *  the number of included s[i] and t[i] by checking for s[i] == 'b' and t[i] == 'a'
 *      ans += (ans_i = (s[i] == 'b') + (t[i] == 'a'))
 *  Each increment of i ans_i doubles
 *  ans_i is bounded by k
 *  
 */

ll ans = 0, ans_i = 1, n, k;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> s >> t;
    // vector<int> z = z_function(s);
    // vector<int> kmp = prefix_function(s);
    for (int i = 0; i < n; i++) {
        ans_i <<= 1;
        ans_i -= (s[i] == 'b') + (t[i] == 'a');
        if (ans_i > k) {
            ans_i = k + 1; // so that compiler doesnt explode
            ans += k;
        } else
            ans += ans_i;
    }

    cout << ans << "\n";
    return 0;
}
