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

vector<vector<bool>> am(16, vector<bool>(16));
vector<vector<int>> al(16);
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

bool fc4(int i1, int i2, int i3, int i4) {
    return (am[i1][i2] && am[i1][i3] && am[i1][i4] && \
            am[i2][i3] && am[i2][i4] && am[i3][i4]);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    for (int i = 0; i < 16; i++) {
        cin >> in;
        stoen.insert({in, i});
        entos.insert({i, in});
    }
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        am[stoen.at(s1)][stoen.at(s2)] = true;
        am[stoen.at(s2)][stoen.at(s1)] = true;
        al[stoen.at(s1)].push_back(stoen.at(s2));
        al[stoen.at(s2)].push_back(stoen.at(s1));
    }

    for (int i = 0; i < 16; i++) {
        if (al[i].size() < 3) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < 16; i++) {
        if (visited_global[i])
            continue;
        queue<int> out;
        queue<int> js;
        bool fc = false;

        int len = al[i].size();
        string bitmask(3, 1);
        bitmask.resize(len, 0);

        do {
            for (int j = 0; j < len; j++)
                if (bitmask[j]) js.push(al[i][j]);
            int i1 = js.front(); js.pop();
            int i2 = js.front(); js.pop();
            int i3 = js.front(); js.pop();

            if (fc4(i, i1, i2, i3)) {
                fc = true;
                out.push(i), out.push(i1), out.push(i2), out.push(i3);
                visited_global[i] = true;
                visited_global[i1] = true;
                visited_global[i2] = true;
                visited_global[i3] = true;
                break;
            }
        } while (next_permutation(bitmask.begin(), bitmask.end()));
        
        if (!fc) {
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
