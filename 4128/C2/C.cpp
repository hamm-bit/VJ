#include <iostream>
#include <array>
using namespace std;
const long long nMOD = 1e9 + 7;
array<long long, 100001> MODDP{};
long long fact(int i) {
    if (MODDP[i] != 0) return MODDP[i];
    return (fact(i - 1) * i) % nMOD;
}

int main() {
    int n;
    cin >> n;
    MODDP[0] = 1ll;
    long long ans = fact(n+1);
    
    // Inclusion exclusion
    int sign = -1;
    for (int i = 2; i <= n+1; i++) {
        long long tmp = (fact(n+2-i) * (n+2-i)) % nMOD;
        ans += tmp * sign;
        cout << ans << "\n";
        sign = -sign;
    }
    return cout << ans << "\n", 0;
}
