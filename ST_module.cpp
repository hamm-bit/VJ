#include <bits/stdc++.h>
// OBSOLETED

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
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

vector<ll> pow2mod(MAX);

ll binpow(ll a, ll b) {
    if (pow2mod[b] != 0)
        return pow2mod[b];
    ll res = binpow(a, b / 2);
    if (b % 2)
        return pow2mod[b] = (res * res * a) % nMOD;
    else
        return pow2mod[b] = (res * res) % nMOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========

    return 0;
}
