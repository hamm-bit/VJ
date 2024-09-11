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

int a, b, c, d;

// =============================================
// ======== Custom functions begin here ========
// =============================================

int bin_search(int in) {
    ll l = 0, r = in + 2, mid = 0, old_mid = 0, in_fig;
    while (l <= r) {
        mid = l + (r - l) / 2;
        // cout << mid << " " << old_mid << "\n";
        if (old_mid == mid) {
            break;
        }
        in_fig = mid * (mid - 1) / 2;
        if (in_fig == (ll) in) {
            break;
        } else if (in_fig > (ll) in) {
            r = mid;
        } else {
            l = mid;
        }
        old_mid = mid;
    }

    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========

    cin >> a >> b >> c >> d;
    ll num0 = 1, num1 = 1;

    if (a == 0) {
        if (b == 0 && c == 0) {
            num1 = bin_search(d);
            if (num1 * (num1 - 1) / 2 == d)
                cout << string(num1, '1');
            else
                cout << "impossible\n";
        } else {
            num1 = b + c;
            if (num1 * (num1 - 1) / 2 == d)
                cout << (string(c, '1') + '0' + string(b, '1'));
            else
                cout << "impossible\n";
        }
        return 0;
    } 
    if (d == 0) {
        if (b == 0 && c == 0) {
            num0 = bin_search(a);
            if (num0 * (num0 - 1) / 2 == a)
                cout << string(num0, '0');
            else
                cout << "impossible\n";
        } else {
            num0 = b + c;
            if (num0 * (num0 - 1) / 2 == a)
                cout << (string(b, '0') + '1' + string(c, '0'));
            else
                cout << "impossible\n";
        }
        return 0;
    }


    num0 = bin_search(a);
    int a_fig = num0 * (num0 - 1) / 2;

    if (a_fig != a) {
        cout << "impossible\n";
        return 0;
    }

    ll sum = b + c;
    if (num0 <= 0) {
        cout << "impossible\n";
        return 0;
    }
    if (sum % num0 != 0) {
        cout << "impossible\n";
        return 0;
    }

    num1 = sum / num0;
    if (num1 <= 0) {
        cout << "impossible\n";
        return 0;
    }
    if (num1 * (num1 - 1) / 2 != d) {
        cout << "impossible\n";
        return 0;
    }

    // String construction possible
    int zero_l = b / num1;
    int zero_m = b % num1;
    
    string output = string(zero_l, '0') + \
                    string(num1 - zero_m, '1') + \
                    string(1, '0') + \
                    string(zero_m, '1') + \
                    string((num0 - zero_l - 1), '0');
    cout << output << "\n";
    return 0;
}
