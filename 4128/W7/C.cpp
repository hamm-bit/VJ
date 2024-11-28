#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll nMOD = (ll) 1e9 + 7;
const int MAX = 5e5 + 5;
const int nMAX = 19;

void arr_print(array<array<int, nMAX>, MAX> z, int m) {
    cout << "\n========================================\n";
    for (auto x : z) {
        for (int a : x)
            cout << a << " ";
        cout << "\n";
    } cout << "\n";
}

void arr_print(array<int, MAX> z, int s, int f) {                                                                       
    for (int i = s; i < f; i++)
        cout << z[i] << " ";                                                                                            
}

// Maximum matching - DINICs


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    
    // determine number of maximum matching '#'s (number of '#'s in a grid SCC)
    // then divide by 2
    // Thus is equivalent to the order of 
    //
    // UPDATE: anti-example for the above:
    //      . # .
    //      # # #
    //      . # .
    // Max-match should yield 1 scoop, but 5 // 2 = 2 != 1
    


    return 0;
}
