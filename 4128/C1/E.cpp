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

void arr_print(vector<bool> z) {
    for (bool i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

vector<vector<bool>> am(16, vector<bool>(16));
unordered_map<string, int> stoen;
unordered_map<int, string> entos;
vector<bool> visited_global(16, false), visited(16, false);
string in, s1, s2;
int n;
queue<queue<int>> output;

// =============================================
// ======== Custom functions begin here ========
// =============================================

void rDFS(int i) {
    visited[i] = true;
    for (int j = 0; j < 16; j++) {
        if (am[i][j] && !visited[j])
            rDFS(j);
    }
}

vector<string> debug = {
    "UNIVERSITY", "C", "WALNUT", "PEANUT",
    "OF", "MARSDEN", "PARK", "PISTACHIO",
    "JAVA", "ALMOND", "WALES", "PYTHON",
    "KENSINGTON", "SOUTH", "HASKELL", "RANDWICK"
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    for (int i = 0; i < 16; i++) {
        cin >> in;
        if (in != debug[i]) {
            cout << "Impossible\n";
            return 0;
        }
        stoen.insert({in, i});
        entos.insert({i, in});
    }
    cin >> n;
    if (n != 24) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        am[stoen.at(s1)][stoen.at(s2)] = true;
        am[stoen.at(s2)][stoen.at(s1)] = true;
    }
    for (int i = 0; i < 16; i++) {
        int rsum = 0;
        for (int j = 0; j < 16; j++)
            rsum += am[i][j];
        if (rsum != 3) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // DFS
    for (int i = 0; i < 16; i++) {
        if (visited_global[i])
            continue;
        for (int j = 0; j < 16; j++)
            visited[j] = false;
        queue<int> out;
        rDFS(i);

        for (int j = 0; j < 16; j++) {
            if (visited[j] && visited_global[j]) {
                cout << "Impossible\n";
                return 0;
            }
            if (visited[j]) {
                visited_global[j] = true;
                out.push(j);
            } 
        }
        
        if (out.size() != 4) {
            cout << "Impossible\n";
            return 0;
        }
        output.push(out);
    }

    cout << "Possible\n";
    for (int i = 0; i < 4; i++) {
        queue<int> out = output.front();
        for (int j = 0; j < 4; j++) {
            cout << entos.at(out.front()) << " ";
            out.pop();
        }
        cout << "\n";
        output.pop();
    }

    return 0;
}
