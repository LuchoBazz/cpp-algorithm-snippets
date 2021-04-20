/**
 * @author      : Luis Miguel Baez <en.luismiguelbaez@gmail.com>
 * @created     : `!v strftime("%B %d, %Y")`
 * @handle      : 🇨🇴 @SorKierkegaard
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define finally(value) {cout << (value) << '\n'; return;}
#define forn(i, b) for(int i = 0; i < int(b); ++i)
#define rep(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rev(i, a, b) for(int i = int(b); i >= int(a); i--)
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
        int T=1, test_number=1;
        cin >> T;
        while (T --> 0) {
            cout << "Case #" << test_number++ << ": ";
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