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
#define umap unordered_map

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

int n, m, s, a;

// =============================================
// ======== Custom functions begin here ========
// =============================================



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> m;
    // umap<int, int>(5);
    vector<int> tymap(m);
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s; j++) {
            cin >> a;
            tymap[a-1]++;
        }
    }
    cout << *min_element(tymap.begin(), tymap.end()) << "\n";

    return 0;
}
