#include <algorithm>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
const int rMAX = 1005;

void arr_print(array<array<pair<int, int>, rMAX>, rMAX> z, int r, int c) {
    cout << "\n========================================\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << "(" << z[i][j].first << " " << z[i][j].second << "); ";
        cout << "\n";
    } cout << "\n";
}

void arr_print(array<int, MAX> z, int s, int f) {                                                                       
    for (int i = s; i < f; i++)
        cout << z[i] << " ";                                                                                            
}

int r, c, klim, g;
array<array<int, rMAX>, rMAX> grid;
array<array<pair<int, int>, rMAX>, rMAX> bounds;
array<pair<int, int>, rMAX * rMAX> as;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========

    cin >> r >> c >> klim;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j], as[i * c + j] = make_pair(grid[i][j], (i << 10) + j);
    sort(as.begin(), as.begin() + r * c);

    int kmin = 1e9 + 7, kmax = -1;
    for (int i = 0; i < klim; i++)
        for (int j = 0; j < klim; j++)
            kmin = min(kmin, grid[i][j]),
            kmax = max(kmin, grid[i][j]);

    bounds[0][0] = make_pair(kmin, kmax);

    for (int j = 0; j <= c-klim; j++) {
        if (j == 0) continue;
        cout << "execute\n";
        kmin = bounds[0][j-1].first;
        kmax = bounds[0][j-1].second;
        for (int k = 0; k < klim; k++) {
            cout << grid[k][j+klim-1];
            kmin = min(kmin, grid[k][j+klim-1]);
            kmax = max(kmax, grid[k][j+klim-1]);
        }
        bounds[0][j] = make_pair(kmin, kmax);
    }
    for (int i = 1; i <= r-klim; i++) {
        for (int j = 0; j <= c-klim; j++) {
            kmin = bounds[i-1][j].first;
            kmax = bounds[i-1][j].second;
            if (j != 0) {
                kmin = min(kmin, grid[i+klim-1][j+klim-1]);
                kmax = max(kmax, grid[i+klim-1][j+klim-1]);
            } else {
                for (int k = 0; k < klim; k++) {
                    kmin = min(kmin, grid[i+klim-1][k]);
                    kmax = max(kmax, grid[i+klim-1][k]);
                }
            }
            bounds[i][j] = make_pair(kmin, kmax);
        }
    }


    arr_print(bounds, r-klim+1, c-klim+1);

    
    int outi = -1, outj = -1;
    // Amortized to 1000x1000
    for (int i = 0; i <= r-klim; i++) {
        for (int j = 0; j <= c-klim; j++) {
            bool flag = false;

            // Find left and right barrier of the "potentail segment"
            pair<int, int> tmp = make_pair(bounds[i][j].second, 0);
            auto it_l = lower_bound(as.begin(), as.begin() + r * c, tmp, 
            [](pair<int, int> a, pair<int, int> b) {
                return a.first < b.first;
            });
            tmp = make_pair(bounds[i][j].first, 0);
            auto it_r = upper_bound(as.begin(), as.begin() + r * c, tmp, 
            [](pair<int, int> a, pair<int, int> b) {
                return a.first > b.first;
            });
            
            // Search all elements between left and right endpoints
            int it_i = it_l->second >> 10, it_j = it_l->second & 0x3FF;
            if (it_i < i || it_i >= i+klim || it_j < j || it_j >= j+klim) flag = true;
            for (auto it = it_l; it++ != it_r;) {
                it_i = it->second >> 10, it_j = it->second & 0x3FF;
                if (it_i < i || it_i >= i+klim || it_j < j || it_j >= j+klim) flag = true;
            }
            it_i = it_r->second >> 10, it_j = it_r->second & 0x3FF;
            if (it_i < i || it_i >= i+klim || it_j < j || it_j >= j+klim) flag = true;

            if (!flag) outi = i, outj = j;
        }
    }

    if (outi != -1)
        return cout << "YES\n" << outi << " " << outj << "\n", 0;
    return cout << "NO\n", 0;
}
