#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <any>
#include <optional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5+1;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

int marks[MAX], n;
ll sum;

// =============================================
// ======== Global variables begin here ========
// =============================================


// ======== NOTES ========
/*
 * Day 1 must be 0
 * Each day a maximum of 1 extra mark is made
 * When water level reaches 0, it either
 *  remains on the top mark; or
 *  makes a new top mark
 *
 * Subproblem:
 *  prev_max
 *  prev_max_idx
 *  max_mark
 *  for i = 0 -> n
 *  if (curr > max_mark)
 *      // max mark has been updated
 *      // recall that only way to grow is either 0 or max_mark
 *      // hence we can reimbue 0s in the smallest fashion
 *      agg_max = max_mark - 1
 *      for (j = i -> prev_max_idx)
 *          // greedily remove 1 per 0 occurence
 *          if (marks[j] == 0)
 *              sum += agg_max
 *              agg_max -= 1
 *          else
 *              sum += (agg_max - marks[j])- 
 *      // assert(agg_max = prev_max)
 *      prev_max_id = i
 *      prev_max = curr
 *      max_mark = curr
 *  else
 *      // if no new limit, do nothing
`*/



// =============================================
// ======== Custom functions begin here ========
// =============================================



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    int prev_max = -1, prev_max_id = -1, max_mark = -1, agg_max = -1;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        if (marks[i] > max_mark) {
            agg_max = marks[i] - 1;
            for (int j = i - 1; j > prev_max_id; j--) {
                int aggr = agg_max - marks[j];
                // cout << aggr << " ";
                sum += aggr;
                agg_max -= (marks[j] == 0 && agg_max > max_mark);
            }
            // cout << "\n";
            // assert(agg_max == prev_max);
            prev_max_id = i;
            prev_max = marks[i];
            max_mark = marks[i];
            // cout << sum << "\n";
        }
    }
    
    for (int j = n - 1; j > prev_max_id; j--)
        sum += max_mark - marks[j];

    cout << sum << "\n";
    return 0;
}
