#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>
using namespace std;
typedef long long ll;

// struct str_min_query {
//     string init = ;
//     string operator()(string a, string b) { return min(a, b); }
// };

struct bool_and_query {
    bool init = true;
    bool operator()(bool a, bool b) { return a && b; }
};

struct ll_sum_query {
    ll init = 0;
    ll operator()(ll a, ll b) { return a + b; }
};

struct ll_max_query {
    ll init = LONG_LONG_MIN;
    ll operator()(ll a, ll b) { return max(a, b); }
};

// query_type must
// - have default constructor (should be automatically created)
// - be callable as q(value_type, value_type) -> value_type
// - have .init member of value_type (should lose to all other values when q()
// is applied)
template <typename value_type, typename query_type, ll max_size>
struct RangeTree {
    value_type rtree[4 * max_size];
    ll _size;
    query_type q;

    RangeTree(ll size) {
        _size = size;
        q = query_type();
        for (ll i = 0; i < _size; i++)
            update(i, q.init);
    }

    value_type query(ll left, ll right) {
        return do_query(left, right, 0, _size);
    }
    void update(ll pos, value_type value) { do_update(pos, value, 0, _size); }

    friend ostream &operator<<(ostream &os, const RangeTree &rt) {
        rt.debug(os, 0, rt._size);
        return os;
    }

  private:
    value_type do_query(ll qL, ll qR, ll cL, ll cR, ll i = 1) {
        if (cL == qL && cR == qR)
            return rtree[i];
        ll mid = (cL + cR) / 2;
        value_type ans = q.init;
        if (qL < mid)
            ans = q(ans, do_query(qL, min(qR, mid), cL, mid, i * 2));
        if (qR > mid)
            ans = q(ans, do_query(max(qL, mid), qR, mid, cR, i * 2 + 1));
        return ans;
    }

    void do_update(ll p, value_type v, ll cL, ll cR, ll i = 1) {
        if (cR - cL == 1) {
            rtree[i] = v;
            return;
        }
        ll mid = (cL + cR) / 2;
        if (p < mid)
            do_update(p, v, cL, mid, i * 2);
        else
            do_update(p, v, mid, cR, i * 2 + 1);
        rtree[i] = q(rtree[i * 2], rtree[i * 2 + 1]);
    }

    void debug(ostream &os, ll cL, ll cR, ll i = 1, ll depth = 0) const {
        for (ll i = 0; i < depth; i++)
            os << "  ";
        os << "[" << cL << "," << cR << ") = ";
        if (rtree[i] == q.init)
            os << "X";
        else
            os << rtree[i];
        os << "\n";
        if (cR - cL > 1) {
            ll mid = (cL + cR) / 2;
            debug(os, cL, mid, i * 2, depth + 1);
            debug(os, mid, cR, i * 2 + 1, depth + 1);
        }
    }
};

ll difficulties[100000];

signed main() {
    ll n, m;
    cin >> n >> m;

    RangeTree<ll, ll_max_query, 100000> max_tree(n);
    RangeTree<bool, bool_and_query, 100000> decreasing_tree(n);
    RangeTree<bool, bool_and_query, 100000> increasing_tree(n);
    RangeTree<ll, ll_sum_query, 100000> sum_tree(n);

    for (ll i = 0; i < n; i++) {
        ll d;
        cin >> d;

        difficulties[i] = d;
        max_tree.update(i, d);
        sum_tree.update(i, d);
        if (i > 0) {
            decreasing_tree.update(i, difficulties[i] <= difficulties[i - 1]);
            increasing_tree.update(i, difficulties[i] >= difficulties[i - 1]);
        }
    }

    for (ll i = 0; i < m; i++) {
        char command;
        cin >> command;

        if (command == 'U') {
            ll index, new_difficulty;
            cin >> index >> new_difficulty;
            index--;

            difficulties[index] = new_difficulty;
            max_tree.update(index, new_difficulty);
            sum_tree.update(index, new_difficulty);
            if (index > 0) {
                decreasing_tree.update(index,
                                       difficulties[index] <=
                                           difficulties[index - 1]);
                increasing_tree.update(index,
                                       difficulties[index] >=
                                           difficulties[index - 1]);
            }
            if (index < n - 1) {
                decreasing_tree.update(index + 1,
                                       difficulties[index + 1] <=
                                           difficulties[index]);
                increasing_tree.update(index + 1,
                                       difficulties[index + 1] >=
                                           difficulties[index]);
            }
        } else if (command == 'M') {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;

            cout << max_tree.query(left, right + 1) << endl;
        } else if (command == 'S') {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;

            cout << sum_tree.query(left, right + 1) << endl;
        } else if (command == 'I') {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;
            if (left == right) {
                cout << 1 << endl;
                continue;
            }

            cout << (increasing_tree.query(left + 1, right + 1) ? 1 : 0) << endl;
        } else if (command == 'D') {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;

            if (left == right) {
                cout << 1 << endl;
                continue;
            }

            cout << (decreasing_tree.query(left + 1, right + 1) ? 1 : 0) << endl;
        }
    }
    
}
