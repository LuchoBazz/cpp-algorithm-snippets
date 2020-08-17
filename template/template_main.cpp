/**
 * @author      : {{NAME}} <{{EMAIL}}>
 * @created     : {{DAY_FULL}} {{MONTH_FULL}} {{DATE}}, {{YEAR}}
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(arr, value) memset(arr, value, sizeof(arr))
#define finally(value) {cout << value << '\n'; return;}
#define ll    int64_t

const int oo = int(1e9);
const ll lloo  = (ll)(1e18);

class Task {
public:
    
    void solveOne(istream &in, ostream &out) {
         {{CURSOR}}
    }
    
    void solve(istream &in, ostream &out) {
        int t=1;
        in >> t;
        while(t--) solveOne(in, out);
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}
