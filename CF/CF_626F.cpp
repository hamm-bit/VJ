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

void arr_print(array<int, nMAX> z, int s, int f) {                                                                       
    for (int i = s; i < f; i++)
        cout << z[i] << " ";                                                                                            
}

int n, k_lim, a;
array<int, nMAX> as{};
int DP[nMAX][nMAX][kMAX];
ll sum = 0ll, cnt = 0ll;


ll KS_r(int i, int g, int k) {
    ll res = 0;

    if (g >= n || k > k_lim) return 0;

    if (i > n) return (g == 0);

    if (DP[i][g][k] != -1) return DP[i][g][k];
        
    if (g == 0) {
        res += KS_r(i + 1, 1, k), res %= nMOD;
        res += KS_r(i + 1, 0, k), res %= nMOD;
    } else {
        int new_k = k + g * (as[i] - as[i - 1]);
        // UPDATE: Do lower order (un-union) first
        res += KS_r(i + 1, g + 1, new_k), res %= nMOD;
        // Union coefficient is `g`
        res += g * KS_r(i + 1, g - 1, new_k), res %= nMOD;
        res += (g + 1) * KS_r(i + 1, g, new_k), res %= nMOD;
    }
    return DP[i][g][k] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> k_lim;
    for (int i = 0; i++ < n;) cin >> as[i];
    sort(as.begin(), as.begin() + (n + 1));

    for (int i = 0; i < n + 1; i++)
        for (int g = 0; g < n + 1; g++)
            for (int k = 0; k < k_lim + 1; k++)
                DP[i][g][k] = -1;

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
    // 
    // We could use DFS to represent the traversal of selecting which ones to unionize
    // By each unit group is seen as a node, a "visit" is making that node do 3 operations
    // Union (g - 1, tot unit group decreases), De-union (g + 1, tot unit group increases)
    //
    // And we have 3 cases:
    //  - Deunion (open a group):   There is only one way to deunion current member from its group
    //  - Union (close a group):    There are g groups that the current member can join into
    //  - Dont union (not closing): The group can stay singular (1), or keep opened (g).
    
    /*
    res = 0
    KS_r(i, g, k):
        # max bound hit, stack ceases to grow
        if (g > n)
            return 0

        # (a path) of nodes traversed, return if there are still unit nodes.
        if (i > n)
            return (g == 1)

        # returned inited memoizer
        if (DP[i][j][k] != -1) return DP[i][j][k]
        
        if (g == 1)
            # init for each-level DFS
            res += KS_r(i + 1, 2, k); res %= nMOD
            res += KS_r(i + 1, 1, k); res %= nMOD
            return res;

        new_k = g * (as[i] - as[i - 1])
        if (new_k <= k_lim)
            res += KS_r(i + 1, g + 1, new_k); res %= nMOD
            res += g * KS_r(i + 1, g - 1, new_k); res %= nMOD
            res += (g + 1) * KS_r(i + 1, g, new_k); res %= nMOD
        DP[i][g][k] = res
    */

    sum = KS_r(1, 0, 0);

    /*
    for (int i = 0; i++ < n + 1;) {
        cout << "\n========================================\n";
        for (int g = 0; g < n + 1; g++) {
            for (int k = 0; k < k_lim + 1; k++)
                cout << DP[i][g][k] << " ";
            cout << "\n";
        }
    }

    cout << "\n========================================\n";
    */
    return cout << sum << "\n", 0;
}
