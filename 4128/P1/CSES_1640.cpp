#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;


int main() {
    int n, x, a;
    unordered_set<int> nset; 
    unordered_map<int, int> pos;
    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> a; 
        if (x-a > 0 && nset.find(x-a) != nset.end())
            return cout << pos.at(x-a) << " " << i + 1 << "\n", 0;
        if (a < x) nset.insert(a), pos.insert({a, i+1});
    }
    return cout << "IMPOSSIBLE\n", 0;
}
