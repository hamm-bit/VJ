#include <cassert>
#include <cstring>
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
const ll MAX = 1e4+2;

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// =============================================
// ======== Global variables begin here ========
// =============================================

int r, rem, quo, h, t, idx;
string msg, out;

// =============================================
// ======== Custom functions begin here ========
// =============================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> r;
    cin >> msg;
    
    int len = msg.length(), T = 2 * r - 2;
    out = string(len, '#');

    quo = len / T, rem = len % T;
    h = quo + (rem != 0);
    t = quo + (rem > r - 1);

    int leftover = (rem > r - 1) ? T - rem : rem;

    for (int i = 0; i < h; i++)
        out[T * i] = msg[i];
    idx = h;

    for (int i = 1; i < r - 1; i++) {
        // for each row
        for (int j = 0; j < quo; j++) {
            out[T * j + i] = msg[idx + j * 2];
            out[T * j + T - i] = msg[idx + j * 2 + 1];
        }
        // non-complete rows
        if (rem >= r) {
            out[T * quo + i] = msg[idx + quo * 2];
            if (i > leftover) {
                out[T * quo + T - i] = msg[idx + quo * 2 + 1];
                idx++;
            }
            idx++;
        } else if (rem > 0) {
            if (i + 1 <= leftover) {
                out[T * quo + i] = msg[idx + quo * 2];
                idx++;
            }
        }
        idx += 2 * quo;
    }

    for (int i = 0; i < t; i++)
        out[T * i + r - 1] = msg[len - t + i];

    cout << out << "\n";

    return 0;
}
