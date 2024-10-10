#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
const int nMAX = 205;
const int kMAX = 1005;

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

int n, k, a;
array<int, nMAX> as{};
array<array<int, nMAX>, nMAX> diff{};
array<array<ll, nMAX>, kMAX> DP{};
ll sum = 0ll, cnt = 0ll;

ll KS(int i, int j, ll curr_k) {
    if (i == n && j == n)
        return 0;

    return 0;
}

ll KS_r(int i, int j, ll curr_k) {
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> k;
    for (int i = 0; i++ < n;) cin >> as[i];
    sort(as.begin(), as.begin() + n);

    // The total imbalance is equivalent to sum of all ranges
    // Start from minimum and check if greatest diff is less than k
    //
    // Similarity: count the number of way to add items into the knapsack
    // without exceeding the total weight limit
    //
    // This however may be to slow to apply, if we were to add pairs each time
    // We can of course encode the "capability distance" between two students
    // But having to do subproblems of counting on each subproblems
    // Will still make this total runtime exponential (still a sizeable factor of 1 << 200)
    //
    // Current determined param: num_stu, dif_sum (standard KS params)

    return 0;
}
