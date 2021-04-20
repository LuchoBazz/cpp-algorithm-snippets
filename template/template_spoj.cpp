/**
 * @created     : `!v strftime("%B %d, %Y")`
 */
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define finally(value) {cout << (value) << '\n'; return;}
#define forn(i, b) for(int i = 0; i < int(b); ++i)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define trav(ref, ds) for(auto &ref: ds)
#define sz(v) ((int) v.size())

using int64 = int64_t;

class Task {
private:

    void clear() {}
    void read() {}

    void solveOne() {
        ;
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
        cout << h;
        if(sizeof...(t)) cout << ' '; print(t...);
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