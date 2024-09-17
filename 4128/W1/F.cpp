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
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5 + 5;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

int as[MAX], pos[MAX], n;
vector<pair<int, int>> swaps;

// =============================================
// ======== Custom functions begin here ========
// =============================================

// Initially it is thought to make least amount of swaps (cycle_length - 1)
// However, the problem becomes much clearer to instead 
// constructively swap sort (identical to qsort without pivoting)
// so we have
/*
 *  ord <- true;
 *  while (ord)
 *      ord <- false
 *      for i : 1 -> n
 *          if (as[i] > as[i + 1])
 *              ord <- true
 *              swaps ++ <pos[i], pos[i + 1]>
 *              swap arr val and pos idx
 *
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> as[i], pos[i] = i;

    bool ord = true;
    while (ord) {
        ord = false;
        for (int i = 1; i < n; i++) {
            if (as[i] > as[i + 1]) {
                ord = true;
                swaps.push_back({pos[i], pos[i + 1]});
                swap(as[i], as[i + 1]), swap(pos[i], pos[i + 1]);
                break;
            }
        }
    }
    cout << swaps.size() << "\n";
    
    for (int s = swaps.size(); s--;)
        cout << swaps[s].first << " " << swaps[s].second << "\n";
    return 0;
}
