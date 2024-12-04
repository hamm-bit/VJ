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

double area(vector <pt > pts) {
    double res = 0;
    int n = pts.size ();
    for (int i = 1; i < n-1; i++) {
        // i = 0 and i = n-1 are degenerate triangles , OK to omit
        // e.g. if i = 1 is ABC , and i = 2 is ACD , then i = 0 is AAB
        res += cross(pts[i] - pts [0], pts[i+1] - pts [0]);
    }
    return res /2.0;
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
