#include <array>
#include <climits>
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
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long

// Edit based on given Qs
const int nMOD = (int) 1e9;
const ll MAX = 1e5 + 5;

// vector<int> DP(MAX);
// vector<vector<int>> DP(MAX, vector<int> MAX);

void arr_print(vector<int> z) {
    for (int i : z) {
        cout << i << " ";
    } cout << "\n";
    return;
}

// Change for suitability
/*
int b_search(int i) {
    ll l = 0ll, r = DP.size();
    ll mid = l + (r - l) / 2, old_mid = -1ll;
    while (l <= r) {
        if (DP[mid] == i || mid == old_mid)
            break;
        else if (DP[mid] > i)
            r = mid;
        else
            l = mid;
    }
    return mid;
}
*/

// =============================================
// ======== Global variables begin here ========
// =============================================

struct S_que {
    ll init = 0;
    ll operator()(ll a, ll b) { return a + b; }
};

struct M_que {
    ll init = LONG_LONG_MIN;
    ll operator()(ll a, ll b) { return max(a, b); }
};

struct B_que {
    bool init = true;
    bool operator()(bool a, bool b) { return a && b; }
};


ll n, m, D, d, x, y;
array<ll, MAX> Ds{};

// =============================================
// ======== Custom functions begin here ========
// =============================================

// q_t must
//  - have default constructor (should be automatically created)
//  - be callable as q(val_t, val_t) -> val_t
//  - have `init` member of val_t (should lose to all other values when q()
// is applied)
template <typename val_t, typename q_t, ll max_size>
struct RT {
    val_t rtree[4 * max_size];
    ll _size;
    q_t q;

    RT(ll size) {
        _size = size;
        q = q_t();
        for (ll i = 0; i++ < _size;)
            update(i, q.init);
    }
    
    void update(ll pos, val_t value) {
        r_upd(pos, value, 0, _size);
    }

    val_t query(ll left, ll right) {
        return r_que(left, right, 0, _size);
    }

    // DEBUG OUTPUT
    friend ostream &operator<<(ostream &os, const RT &rt) {
        rt.debug(os, 0, rt._size);
        return os;
    }

    private:
    // Recursively update the tree by binary divide segments
    // NOTE: DEPENDENT ON `q` AND CAN FAIL, VARY BY SITUATIONS
    void r_upd(ll p, val_t v, ll cL, ll cR, ll i = 1) {
        if (cR - cL == 1) {
            rtree[i] = v;
            return;
        }
        ll mid = (cL + cR) / 2;
        if (p < mid)    r_upd(p, v, cL, mid, i * 2);
        else            r_upd(p, v, mid, cR, i * 2 + 1);
        rtree[i] = q(rtree[i * 2], rtree[i * 2 + 1]);
    }


    // Recursively query the tree by binary divide segments
    // NOTE: DEPENDENT ON `q` AND CAN FAIL, VARY BY SITUATIONS
    val_t r_que(ll qL, ll qR, ll cL, ll cR, ll i = 1) {
        if (cL == qL && cR == qR)   return rtree[i];
        ll mid = (cL + cR) / 2;
        val_t ans = q.init;
        if (qL < mid)
            ans = q(ans, r_que(qL, min(qR, mid), cL, mid, i * 2));
        if (qR > mid)
            ans = q(ans, r_que(max(qL, mid), qR, mid, cR, i * 2 + 1));
        return ans;
    }


    // DEFAULT TO BEING BARRED FROM BEING CALLED DIRECTLY
    // Vary config and pub/priv based on situations
    void debug(ostream &os, ll cL, ll cR, ll i = 1, ll h = 0) const {
        for (ll i = 0; i < h; i++)
            os << "  ";
        os << "[" << cL << "," << cR << ") = ";
        if (rtree[i] == q.init)     os << "X";
        else                        os << rtree[i];
        os << "\n";
        if (cR - cL > 1) {
            ll mid = (cL + cR) / 2;
            debug(os, cL, mid, i * 2, h + 1);
            debug(os, mid, cR, i * 2 + 1, h + 1);
        }
    }
};

// This is genuinely some of the worst code i've written

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========
    cin >> n >> m;

    RT<ll, M_que, MAX> max_tree(n);

    return 0;
}
