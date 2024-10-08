#include <cstdio>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <array>
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

int n, a, amax = -1;
array<ll, MAX> sums{}, freq{};

// =============================================
// ======== Custom functions begin here ========
// =============================================



/*
 *  Note that the order of the list does not matter.
 *  In fact it does not even require a sort, we can just keep track of
 *  a_{k+1} and a_{k-1} by using them as indices as arrays of their frequency..
 *  sum of arbitrary a_k's is equal to \sum {a_i} - \sum {a_{k+1} + a_{k-1}}
 *  
 *  To maximise the a_k's is to minimize the a_{k+1} + a_{k-1}'s
 *
 *  freq(i) = { count }
 *  Recurrence relation
 *      For del(k) = min(del(k - 1), del(k + 1));
 *      del(k):
 *          
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a, freq[a]++, amax = max(amax, a);

    sums[1] = freq[1];
    for (int i = 1; i++ < amax;)
        sums[i] = max(sums[i-1], sums[i-2] + freq[i] * i);

    cout << sums[amax];
    return 0;
}
