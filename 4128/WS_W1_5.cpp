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

string bruh;
vector<int> freq(26);
queue<int> non;

// =============================================
// ======== Custom functions begin here ========
// =============================================

string nice_substring(string in) {
    int n = in.size();
    int qCount = 0;
    string output;
    for (char c : in) {
        if (c == 'q')
            qCount++;
        else
            freq[c - 'A']++;
    }
    int num_q = 0;

    for (int i = 0; i < n; i++) {
        num_q += (freq[i] < 0);
        non.push(i);
    }

    if (qCount < num_q)
        return string("-1");

    for (int i = 0; i < n; i++) {
        if (qCount < 0) {
            // replace
            in[i] = (char) (non.front() + 'A');
            non.pop();
        } else
            in[i] = 'A';
    }
    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> bruh;
    cout << nice_substring(bruh) << "\n";

    return 0;
}
