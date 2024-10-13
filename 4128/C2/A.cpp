#include <bits/stdc++.h>
#include <functional>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 2e5 + 5;
const int nMAX = 19;

void arr_print(array<array<int, nMAX>, MAX> z, int m) {
    cout << "\n========================================\n";
    for (auto x : z) {
        for (int a : x)
            cout << a << " ";
        cout << "\n";
    } cout << "\n";
}

void arr_print(array<int, MAX> z, int s, int f) {                                                                       
    for (int i = s; i < f; i++)
        cout << z[i] << " ";                                                                                            
}

int n, r, tot;
array<int, MAX> rs{};
queue<int> out;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n;
    for (int i = 0; i < n; i++) cin >> rs[i];
    sort(rs.begin(), rs.begin() + n, greater<int>());
    
    int time = 1e6+1, ans = 0;
    for (;ans < n && time > 0; ans++)
        time = min(time, rs[ans]), time--;

    cout << ans << "\n";
    for (int i = 0; i < ans; i++)
        cout << rs[i] << " ";
    return cout << "\n", 0;
}
