// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 1e5 + 5;
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

int t, n;

// For a presorted list
// The sum of all set differences are essentially equal to
// the sum of all ending numbers minus the sum of all starting numbers of sequences
//
// The left most element, by order will appear 2^n-1 times
// Second left most being 2^n-2, etc..
// the ith element would appear 2^n-i-1 times
//
// Vice versa, the right most element would appear 2^n-1 times
// second right most 2^n-2 times etc..
// ith right most element would appear 2^n-i-1 times
// Note in this case the index is reducing
//
// The total set difference would be the difference of the above two sum

// TODO: implement a array to store 2^n modulo nMOD
// Cannot use pow() or 2 << () directly as it will overflow if n > 64
// also it will be too slow

int sumright(vector<ll> S) {
    ll sum = 0;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        sum += (S[i] * binpow(2, i)) % nMOD;
        sum %= nMOD;
    }
    return (int) sum;
}

int sumleft(vector<ll> S) {
    ll sum = 0;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        sum += (S[i] * binpow(2, n-i-1)) % nMOD;
        sum %= nMOD;
    }
    return (int) sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pow2mod[0] = 1;

    // ======== Main begins here ========
    cin >> t;
    for (;t--;) {
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(nums.begin(), nums.end());
        cout << sumright(nums) - sumleft(nums) << "\n";
    }
    return 0;
}
