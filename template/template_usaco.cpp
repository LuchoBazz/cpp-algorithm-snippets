/**
 * @author      : Luis Miguel Baez <es.luismiguelbaez@gmail.com>
 * @created     : `!v strftime("%B %d, %Y")`
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define finally(value) {cout << (value) << '\n'; return;}

class Task {
private:
    
    void solveOne(istream &in, ostream &out) {
        
    }

public:
    void solve(istream &in, ostream &out) {
        int t=1;
        in >> t;
        while(t--) solveOne(in, out);
    }
};

void set_usaco(string filename="") {
    if(int(filename.size())) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set_usaco("");
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}

// THINGS TO KEEP IN MIND
//   * int overflow, time and memory limits
//   * Special case (n = 1?)
//   * Do something instead of nothing and stay organized
//   * Don't get stuck in one focus

// TIME AND MEMORY LIMITS
//   * 1 second is approximately 10^8 operations (c++)
//   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
//   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
//   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
//   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB