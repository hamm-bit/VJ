// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <array>

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

int n;
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

// The minimum value achievable must have power of 1 on all of its prime factors 
// The number of operations should be bounded by the number of square roots.
// Which is dictated by the indice of the smallest power of 2 larger
// than the largest indices of n's prime factors 
//
// Execute a factor tree, find the prime factors with the largest indice,
// find the indice of the smallest power of two larger than that indice
// The number of operations is equal to the indice of power of two + 1
// The smallest achievable number is equal to the product of all prime factors

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========

    cin >> n;
    int fact_max = 0, fact_min = 20, ans_flat = 1, ans_its = 1;
    for (int i = 2; i <= 1000000; i++) {
        int fact_idx = 0;
        while (n % i == 0) {
            fact_idx++;
            n /= i;
            if (n % i != 0) ans_flat *= i;
        }
        fact_max = max(fact_max, fact_idx);
        if (fact_idx != 0) fact_min = min(fact_min, fact_idx);
    }
    // largest prime factor indice is bounded by log_2(1000000) ~= 20 < 32 = 2^5
    // So the largest number of steps for all numbers
    cout << fact_max << " " << fact_min << "\n";
    ans_its += (fact_max > 16) + (fact_max > 8) + \
        (fact_max > 4) + (fact_max > 2) + (fact_max > 1);
    ans_its -= ((fact_max == 16 || fact_max == 8 || fact_max == 4 \
        || fact_max == 2 || fact_max == 1) && fact_max == fact_min);

    return cout << ans_flat << " " << ans_its << "\n", 0;
}
