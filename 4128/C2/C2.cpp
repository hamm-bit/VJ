#include <iostream>
#include <vector>
using namespace std;
const long long nMOD = 1e9+7;

int main() {
    int n;
    cin >> n, n++;
    vector<vector<long long>> DP(n + 1, vector<long long>(2, 0));
    
    // Derangement
    DP[1][0] = 0, DP[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        DP[i][0] = ((i - 1) * (DP[i - 1][0] + DP[i - 1][1]) % nMOD) % nMOD;
        DP[i][1] = DP[i - 1][0];
    }
    return cout << (DP[n][0] + DP[n][1]) % nMOD << "\n", 0;
}
 
