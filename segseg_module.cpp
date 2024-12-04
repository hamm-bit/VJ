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

typedef pair <pt , pt > seg;

bool collinear (seg ab , seg cd) { // all four points collinear
    pt a = ab.first , b = ab.second , c = cd.first , d = cd.second;
    return zero(cross(b - a, c - a)) &&
           zero(cross(b - a, d - a));
}

double sq(double t) { return t * t; }

double dist(pt p, pt q) { return sqrt(sq(p.x - q.x) + sq(p.y - q.y)); }

bool intersect (seg ab , seg cd) {
    pt a = ab.first , b = ab.second , c = cd.first , d = cd.second;
    if ( collinear (ab , cd)) {
        double maxDist = max ({ dist(a, b), dist(a, c), dist(a, d),
                                dist(b, c), dist(b, d), dist(c, d)});
        return maxDist < dist(a, b) + dist(c, d) + EPS;
    }
    // only finds proper intersections
    // for non -proper , have ccw return an int
    // then return whether both products of ccws are <= 0
    return ccw(a, b, c) != ccw(a, b, d) &&
           ccw(c, d, a) != ccw(c, d, b);
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
