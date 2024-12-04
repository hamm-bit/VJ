#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = (1 << 18) + 5;
const int nMAX = 19;

// Global Variables
int n, m, k, as[nMAX], cs[nMAX][nMAX];
int x, y, c;
ll DP[MAX][nMAX], r = -1;

// Custom Functions
auto up = [](ll &x, ll y){x < y ? x = y : 0;};

void arr_print(int z[19][19], int s=0, int f=nMAX) {
    for (int i = s; i < f; i++) {
        for (int j = s; j < f; j++) 
            cout << z[i][j] << " ";
        cout << "\n";
    }
}

// ==== MAIN ====
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> as[i], DP[1 << i][i] = as[i];
    for (;k--;) {
        cin >> x >> y >> c;
        cs[x-1][y-1] = c;
    }

    for (int i = 1; i < (1 << n); i++) {
        if (__builtin_popcount(i) == m)
            for (k = 0; k < n; k++) r = max(r, DP[i][k]);
        for (int j = 0; j < n; j++) if (i >> j & 1)
            for (k = 0; k < n; k++) {
                // DP[i || 1 << k][k] can be improved from
                // DP[i][j] with cs[j][k] + as[k];
                if (~i >> k & 1)
                    up(DP[i | 1 << k][k], DP[i][j] + (ll) cs[j][k] + (ll) as[k]);
            }
    }
    cout << r << "\n";
    return 0;
}
