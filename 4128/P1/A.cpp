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

int n, a;

// =============================================
// ======== Custom functions begin here ========
// =============================================



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // ======== Main begins here ========
    string input;
    bool fishy = false;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input != "mumble") {
            a = stoi(input);
            if (a != i + 1) 
                fishy = true;
        }
    }
    cout << ((fishy) ? "something is fishy\n" : "makes sense\n");
    return 0;
}
