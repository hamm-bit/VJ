#include <iostream>
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

// Converts a string of length n to an n-length array of indices
// where z[i] indicates the length of the longest substring from s[i]
// that is the prefix of the string s
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        // If i falls under the matched segment, load segment
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        // Increases z[i] until we hit a mismatch in the prefix of s
        // Or we hit the end of the string
        // If we came from the matched segment, then s would not match and skip
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
            cout << "in: \t";
            // arr_print(z);
        }
        // Update the left segment
        // If it is the beginning of a new matched segment, update the right as well
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
        cout << "nin: \t";
        // arr_print(z);
    }
    return z;
}

// Converts a string of length n to an n-length array of indices
// where z[i] indicates the current position of this character
// in the prefix of s
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        // arr_print(pi);
    }
    return pi;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    // vector<int> z = z_function(s);
    // vector<int> kmp = prefix_function(s);

    return 0;
}
