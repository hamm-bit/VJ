#include <iostream>

using namespace std;

int main() {
    long long n, a, sum = 0, nc2;
    cin >> n, nc2 = n * (n + 1) / 2;
    for (int j = 0; j++ < n - 1;)
        cin >> a, sum += a;
    return cout << nc2 - sum << "\n", 0;
}
