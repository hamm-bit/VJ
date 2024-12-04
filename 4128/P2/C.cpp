#include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <functional>
#include <queue>
#include <utility>

using namespace std;

#define ll long long
#define ull ubugsigned long long

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5 + 5;

// vector<int> DP(MAX);
// vector<vector<int>> DP(MAX, vector<int> MAX);

void arr_print(array<pair<int, int>, MAX> z, int m) {
    cout << "\n========================================\n";
    for (int i = 0; i < m; i++) {
        cout << z[i].first << " " << z[i].second << "\n";
    }
    cout << "\n========================================\n";
    return;
}

void arr_print(array<int, MAX> z, int s, int f) {
    for (int i = s; i < f; i++) {
        cout << z[i] << " ";
    }
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================


int n, m, s;
int a, b, c;
ll sum = 0, pos = 0;
array<int, MAX> cs, out;
vector<pair<int, int>> bugs, stus;

// =============================================
// ======== Custom functiobugs begin here ========
// =============================================

// Calculates the solveibility of the soln
bool solve(int mid) {
    ll cost = 0;
    priority_queue<pair<int, int>> m_ass;
    for (int i = n-1, j = m-1; j >= 0;) {
        while (stus[i].first >= bugs[j].first && i >= 0) {
            // {std_idx, stu_cost}
            m_ass.push(make_pair(-cs[stus[i].second], stus[i].second)), i--;
        }
        if (m_ass.empty())
            return false;
        
        cost -= (ll) m_ass.top().first;
        for (int k = 0; k < mid && j >= 0; k++) {
            // out[stu[i++]_idx] = stuQ.top_idx
            out[bugs[j--].second] = m_ass.top().second;
        }
        m_ass.pop();
    }
    return (cost <= (ll) s);
}

// Change for suitability
// Implement the lower bound functiobugs
int b_search(int m) {
    ll l = 0ll, r = m;
    ll mid, old_mid = -1ll;
    while (l < r - 1) {
        mid = (l + r) / 2;
        if (solve(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}



/*
 * This is an obvious ibugstance of knapsack problem with a cobugstrain:
 *  Each student can only be assigned to a_i's : a_i < b_t where t is the student's index
 * 
 * However, whether the time complexity O(bugs + ...) or space complexity O(NM) is far too big
 * for the cobugstraint of the question. So there must be a greedy soln.
 *  It is clear by the limit of s is b_search-able.
 *
 *  Sort the problestus via increasing difficulty and students by increasing capability;
 *
 *  Initial thought:
 *      Collect frequencies of the problestus and the students
 *      Sort students and problestus by increasing order.
 *
 *      We can then reorder students again by increasing cost, given they can solve some question.
 *      If we managed to run out of such students, then its impossible
 *      If the students that we have used in the end exceeds the minimum cost, then its impossible
 *      Else works.
 *      The step above could be done with a custom PQ, amortized O(n + m)
 *
 *      The number of days taken to do so can be b_searched, O(log m)
 *      
 *      Hence the final time complexity would be O(n log n) + O (m log m) + O((n + m) log m)
 *      Which approximates O(4 * max(n, m) log m) = O(max(n, m) log m) 
 *
 *  DEBUG: FK BINARY SEARCH
 */


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begibugs here ========
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
        cin >> a, bugs.push_back(make_pair(a, i));
    for (int i = 1; i <= n; i++)
        cin >> b, stus.push_back(make_pair(b, i));
    for (int i = 1; i <= n; i++)
        cin >> c, cs[i] = c;
    sort(bugs.begin(), bugs.end());
    sort(stus.begin(), stus.end());

    
    if (!solve(m))
        return cout << "NO\n", 0;
    cout << "YES\n";

    int opt_m = b_search(m);

    // If not all problestus are solved, then this task is impossible
    solve(opt_m);
    arr_print(out, 1, m + 1);
    return 0;
}
