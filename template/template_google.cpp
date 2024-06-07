/**
 * @author      : Luis Miguel Baez <en.luismiguelbaez@gmail.com>
 * @created     : `!v strftime("%B %d, %Y")`
 * @handle      : @LuchoBazz
 */

#include <bits/stdc++.h>

using namespace std;

class Task {
  private:
    void clear() {}
    void read() {}

    void solveOne() {
        ;
    }

  public:
    void solve() {
        int T = 1, test_number = 1;
        cin >> T;
        while (T-- > 0) {
            cout << "Case #" << test_number++ << ": ";
            clear();
            read();
            solveOne();
        }
    }

  private:
    void print() { cout << '\n'; }
    template <class H, class... T> void print(const H &h, const T &...t) {
        cout << h;
        if (sizeof...(t))
            cout << ' ';
        print(t...);
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
