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

const double EPS = 1e-8;
typedef pair <double , double > pt;
#define x first
#define y second
pt operator -(pt a, pt b) {
    return pt(a.x - b.x, a.y - b.y);
}

bool zero(double x) {
    return fabs(x) <= EPS;
}

double cross(pt a, pt b) {
    return a.x*b.y - a.y*b.x;
}

// true if left or straight
// sometimes useful to instead return an int
// -1, 0 or 1: the sign of the cross product
bool ccw(pt a, pt b, pt c) {
    return cross(b - a, c - a) >= 0;
}

vector <pt> half_hull (vector <pt > pts) {
    vector <pt > res;
    for (int i = 0; i < pts.size (); i++) {
        // ccw means we have a left turn; we don 't want that
        while (res.size () >= 2 &&
               ccw(pts[i], res[res.size () -1], res[res.size () -2])) {
            res.pop_back ();
        }
        res. push_back (pts[i]);
    }
    return res;
}

vector <pt> convex_hull (vector <pt > pts) {
    sort(pts.begin (), pts.end ());
    vector <pt > top = half_hull (pts);
    reverse(pts.begin (), pts.end ());
    vector <pt > bottom = half_hull (pts);
    top.pop_back ();
    bottom.pop_back ();
    vector <pt > res(top.begin (), top.end ());
    res.insert(res.end (), bottom.begin (), bottom.end ());
    return res;
}

typedef pair <double , double > pt;
struct line {
    double a, b, c;
};
struct half_plane {
    line l;
    bool neg; // is the inequality <= or >=
};
pt intersect (line f, line g) {
    double d = f.a*g.b - f.b*g.a;
    double y = (f.a*g.c - f.c*g.a)/(f.b*g.a - f.a*g.b);
    double x = (f.c*g.b - f.b*g.c)/(f.b*g.a - f.a*g.b);
    return pt(x, y);
}
bool in_half_plane ( half_plane hp , pt q) {
    if (hp.neg)
        return hp.l.a*q.x + hp.l.b*q.y + hp.l.c <= EPS;
    else
        return hp.l.a*q.x + hp.l.b*q.y + hp.l.c >= -EPS;
}

vector <pt> intersect_half_planes (vector <half_plane > half_planes ) {
    int n = half_planes .size ();
    vector <pt> pts;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pt p = intersect ( half_planes [i].l, half_planes [j].l);
            bool fail = false;
            for (int k = 0; k < n; k++)
                if (!in_half_plane ( half_planes [k], p))
                    fail = true;
            if (!fail)
                pts. push_back (p);
        }
    }
    vector <pt > res = pts;
    if (pts.size () > 2)
        pts = convex_hull (res);
    return pts;
}

vector<ll> pow2mod(MAX);

ll binpow(ll a, ll b) {
    if (pow2mod[b] != 0)
        return pow2mod[b];
    ll res = binpow(a, b / 2);
    if (b % 2)
        return pow2mod[b] = (res * res * a) % nMOD;
    else
        return pow2mod[b] = (res * res) % nMOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======== Main begins here ========

    return 0;
}
