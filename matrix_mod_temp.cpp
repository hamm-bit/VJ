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

// Implementation for square matrices .
struct Matrix {
    int n;
    vector <vector <long long >> v;
    // Assume these have been implemented .
    Matrix(int _n) : n(_n) {
        v.resize(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i]. push_back (0);
    }

    Matrix operator *( const Matrix &o) const {
        Matrix res(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res.v[i][j] += v[i][k] * o.v[k][j];
        return res;
    }
    
    static Matrix getIdentity (int n) {
        Matrix res(n);
        for (int i = 0; i < n; i++)
            res.v[i][i] = 1;
        return res;
    }

    Matrix operator ^( long long k) const {
        Matrix res = Matrix :: getIdentity (n);
        Matrix a = *this;
        while (k) { // building up in powers of two
            if (k&1) res = res*a;
            a = a*a;
            k /= 2;
        }
        return res;
    }
};

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
