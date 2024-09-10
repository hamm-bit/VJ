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
const int MAX = 1e5;
const int nMIN = (int) -1e9 - 1;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

int t, n, a, a_old = 0, a_max;
ll sum = 0;

// =============================================
// ======== Custom functions begin here ========
// =============================================



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> t;
    for (;t--;) {
        sum = 0;
        cin >> n;
        cin >> a;
        a_max = a;
        a_old = a;
        n--;
        for (;n--;) {
            cin >> a;
            if (a_old < 0 && a > 0) {
                sum += a_max;
                a_max = 0;
            } else if (a_old > 0 && a < 0) {
                sum += a_max;
                a_max = nMIN;
            }
            a_max = max(a_max, a);
            a_old = a;
        }
        cout << sum + a_max << "\n";
    }
    return 0;
}
