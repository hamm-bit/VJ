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

// =============================================
// ======== Global variables begin here ========
// =============================================

ll n, cpn_day = 0;
ll k, cpns = 0, cpns_prev = -1;

// =============================================
// ======== Custom functions begin here ========
// =============================================



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n;
    cin >> k;
    ll l = 0, r = n + 2;
    while (l < r) {
        cpn_day = l + (r - l) / 2;
        cpns = (cpn_day + 1) * cpn_day / 2 - (n - cpn_day);
        if (cpns == k || cpns == cpns_prev)
            break;
        else if (cpns < k)
            l = cpn_day;
        else
            r = cpn_day;
        cpns_prev = cpns;
    }
    cout << n - cpn_day << "\n";

    return 0;
}
