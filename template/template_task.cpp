/**
 * @created     : `!v strftime("%B %d, %Y")`
 * @handle      : @LuchoBazz
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define PB push_back
#define finally(value) {cout << (value) << '\n'; return;}
#define forn(i, b) for(int i = 0; i < int(b); ++i)
#define forr(i, b) for(int i = int(b)-1; i >= 0; i--)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define rev(i, b, a) for(int i = int(b); i >= int(a); i--)
#define trav(ref, ds) for(auto &ref: ds)
#define SZ(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _ << ' ' <<
 
using int64 = long long;
 
#ifdef DEBUG 
#include "debug.h"
#else
#define debug(...) 42
#endif

class Task {
private:
    $1
    void clear() {$2}
    void read() {$3}

    void solveOne() {
        $4
    }

public:
    void solve() {
        int T=1;
        cin >> T;
        while (T --> 0) {
            clear();
            read();
            solveOne();
        }
    }
private:
    void print() {cout << "\n";}
    template<class H, class... T> void print(const H& h, const T&... t) {
        cout << h; if(sizeof...(t)) cout << ' '; print(t...);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Task solver;
    solver.solve();
    cout.flush();
    return 0;
}