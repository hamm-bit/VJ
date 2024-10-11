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
    //
    // The typical KS (max) would have a recurrence of
    //  if (k - as[i] > 0)
    //      DP[i][k] += max(DP[i - 1][k - as[i]] + v[i], DP[i][k - 1]);
    // 
    // Counting is much more complex, since all cases must be considered
    // Specifically made harder due to n being larger than 64 
    // (n = 200 on the surface, but actually somewhere between 200 and 200C2)
    // Therefore preprocessing (like trailing sum) is not realistic
    //
    
    // UPDATE: We could initialize from when all students are in groups
    // that contains them individually.
    //
    // We then start to unionize them
    // Each loop we could unionize the two groups.
    // index in order: groups done, groups that contains one member (unit group), total imbalance 
    
    /*
    KS_rec(i, g, k):
        if (g == 200)
            # max bound hit, stack ceases to grow
            return 0
        if (g == 1)
            # recursion done, KS finishes
            return 0
        new_k = g * as[i - 1]
        if (new_k <= k_lim):
            KS_rec(i + 1, g - 1, new_k)
            KS_rec(i + 1, g, new_k)
            KS_rec(i + 1, g + 1, new_k)
        DP[i][j][k]++

    */

    return 0;
}
