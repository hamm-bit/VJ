#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
const int kMAX = 1005;
const int nMAX = 1005;

void arr_print(array<array<int, nMAX>, MAX> z, int m = 0) {
    cout << "\n========================================\n";
    for (auto x : z) {
        for (int a : x)
            cout << a << " ";
        cout << "\n";
    } cout << "\n";
}

void arr_print(array<int, nMAX> z, int s, int f) {                                                                       
    for (int i = s; i < f; i++)
        cout << z[i] << " ";                                                                                            
}

int n, k_lim;
array<int, nMAX> as{}, bs{};
array<array<int, kMAX>, nMAX> DP{};

int dp(int i, int j) {
    if (abs(j) > k_lim)
        return 0;
    
    if (i > n)
        return 0;
    
    if (DP[i][j] != -1)
        return DP[i][j];

    return DP[i][j] = max(dp(i+1, j-1) + bs[i], dp(i+1, j+1) + as[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> k_lim;
    for (int i = 0; i < n; i++) cin >> as[i] >> bs[i];
    for (auto& row : DP) fill(DP.begin(), DP.end(), -1);

    DP[0][0] = 0;
    for (int i = 1; i < n; i++) {
        // For each task Arda is on,
        // If the absolute diff is 0, then trial Bimala
        // If the aboslute diff is i (Arda or Bimala has done all the tasks up to now), Arda
        // In between, set by comparison
        for (int k = 0; k <= i; k++) {
            if (k > 0 && DP[i-1][k] != -1) DP[i][k] = DP[i-1][k-1] + as[i];
            else if (k < i && DP[i-1][k] != -1) DP[i][k] = max(DP[i][k], DP[i-1][k] + bs[i]);
        }
    }
    
    cout << max_element(DP[n].begin(), DP[n].end());
    return 0;
}
