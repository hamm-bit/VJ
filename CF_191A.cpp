#include <iostream>
#include <algorithm>
#include <string>
#include <any>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define ull unsigned long long int

int n;

// Main diagonal of this matrix represent length of valid dynasties 
vector<vector<int>> DP(26, vector<int>(26, 0));
// DP[i][j] indicates the sequence of kings with character prefix i and suffix j

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    string name;
    
    for (int k = 0; k < n; k++) {
        cin >> name;
        int l = name.front() - 'a', r = name.back() - 'a', s = name.size();
        for (int i = 0; i < 26; i++) {
            int chain_temp = ((int) DP[i][l] != 0) * (DP[i][l] + s);
            DP[i][r] = max(DP[i][r], chain_temp);
        }
        DP[l][r] = max(DP[l][r], s);
    }
    
    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, DP[i][i]);
    cout << ans;
    
    return 0;
}
