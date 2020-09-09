/**
 * @author      : Luis Miguel Baez <es.luismiguelbaez@gmail.com>
 * @created     : `!v strftime("%B %d, %Y")`
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define finally(value) {cout << (value) << '\n'; return;}

class Task {
public:
    
    void solveOne(istream &in, ostream &out) {
        
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
