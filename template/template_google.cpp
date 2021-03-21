/**
 * @author      : Luis Miguel Baez <en.luismiguelbaez@gmail.com>
 * @created     : `!v strftime("%B %d, %Y")`
 * @handle      : 🇨🇴 @SorKierkegaard
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define finally(value) {cout << (value) << endl; return;}
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

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Task solver;
    solver.solve();
    cout.flush();
    return 0;
}

// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one approach

// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB