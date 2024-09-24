#include <iostream>
#include <cmath>
#include <fstream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <array>
#include <stack>
#include <any>
#include <optional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long
#define umap unordered_map

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 2e5+5;

void arr_print(array<pair<int, int>, MAX> z, int m) {
    for (int i = 0; i < m; i++) {
        cout << z[i].first << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

int n, k;
int sum = 0, s, f, curr = 0;
array<pair<int, int>, MAX> tx{};
multiset<int> tq;

// =============================================
// ======== Custom functions begin here ========
// =============================================

bool pair_cmp(pair<int, int> t1, pair<int, int> t2) {
    return (t1.first < t2.first || (t1.first == t2.first && t1.second < t2.second));
}

// UPDATE:
// Considering situation of 3 classrooms, after assigning first two instances,
// followed by two immediately valid starting time with extremely long duration
// After the two in the sorted sequence we have a chain of small events.
//
// The algorithm will put the two extremely long sequence to the very end and (possibly)
// never be counted.
//
// However the optimum would actually be have them 
//
// We could accomodate this by adding a pq to maintain all the room status instead
// Since greedy order is no longer in series but in parallel
//
// DEBUG:
// apparently c++ pq is made of crap, the custom operations is the
// opposite order of the priority.
//
// HABBIT:
// ======== USE NEGATIVE VALUES IN PQ / (M)SETS and other ordered structs ========
//
// UPDATE:
// A singular priority queue is not enough to distinguish the dimension of data
// *Raise the {long, long, [short] x n} example*
// The example above shows two edge cases where one of them invalidates
// The minimum end time order, the other minimum start time order.
//
// This is where DP becomes a no-brainer (in fact a trivial soln). However it is too slow.
//
// We could remove the activity that ends the most recent
// DEBUG: Priority queue comparison is fucked lets use a multiset :skull:
// DEBUG: STL array can be bounded by arr.begin() + n

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        tx[i] = make_pair(f, s);
    }
    sort(tx.begin(), tx.begin() + n);

    // Saves a branch by initing `tq` with k amounts of 0
    for (int i = 0; i < n; i++) {
        auto it = tq.lower_bound(-tx[i].second);
        // cout << tx[i].first << " " << tq.top() << "\n";
        // cout << *it.first << " " << *it.second << "\n";
        if (it == tq.end()) {
            if (tq.size() < k) {
                tq.insert(-tx[i].first - 1);
                sum++;
            }
            continue;
        }
        tq.erase(it);
        tq.insert(-tx[i].first - 1);
        sum++;
    }

    cout << sum << "\n";

    return 0;
}
