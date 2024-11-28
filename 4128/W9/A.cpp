// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
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

int sumright(vector<ll> S) {
    ll sum = 0;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        sum += (S[i] * (ll) pow(2, i)) % nMOD;
        sum %= nMOD;
    }
    return (int) sum;
}

int sumleft(vector<ll> S) {
    ll sum = 0;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        sum += (S[i] * (ll) pow(2, n-i-1)) % nMOD;
        sum %= nMOD;
    }
    return (int) sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> t >> n;
    vector<ll> nums(n);
    for (;t--;)
        for (int i = 0; i < n; i++)
            cin >> nums[i];
    
    return cout << sumright(nums) - sumleft(nums) << "\n", 0;
}
