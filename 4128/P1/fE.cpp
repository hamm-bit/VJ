#include <iostream>
using namespace std;
// make it fast ong
char s[510000], t[510000];
long long i, n, k, out, tmp=2;
int main() {
    scanf("%lld %lld%s%s", &n, &k, s + 1, t + 1);
    for (int i = 1; i <= n; tmp <<= 1, i++) {
        tmp -= (s[i] == 'b') + (t[i] == 'a');
        out += min(tmp = (tmp > k) ? k + 1 : tmp, k);
    }
    printf("%lld\n", out); 
    return 0;
}
