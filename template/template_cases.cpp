/**
 * @created     : `!v strftime("%B %d, %Y")`
 * @handle      : @LuchoBazz
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define _ << ' ' <<
#define PB push_back
#define SZ(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ms(arr, value) memset(arr, value, sizeof(arr))
#define infinity while(1)
#define unreachable assert(false && "Unreachable");

#define overload4(a, b, c, d, e, ...) e
#define for1(a) for(int i = 0; i < int(a); ++i)
#define for2(i, a) for(int i = 0; i < int(a); ++i)
#define for3(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define for4(i, a, b, c) for(int i = int(a); i <= int(b); i += int(c))
#define rof1(a) for(int i = int(a)-1; i >= 0; --i)
#define rof2(i, a) for(int i = int(a)-1; i >= 0; --i)
#define rof3(i, a, b) for(int i = int(b); i >= int(a); --i)
#define rof4(i, a, b, c) for(int i = int(b); i >= int(a); i -= int(c))
#define forn(...) overload4(__VA_ARGS__, for4, for3, for2, for1)(__VA_ARGS__)
#define rof(...)  overload4(__VA_ARGS__, rof4, rof3, rof2, rof1)(__VA_ARGS__)

const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const string YES = "YES";
const string NO = "NO";

const int d4x[4] = {0, -1, 1, 0};
const int d4y[4] = {-1, 0, 0, 1};
const int d8x[8] = {-1, 0, -1, 1, -1, 1, 0, 1};
const int d8y[8] = {-1, -1, 0, -1, 1, 0, 1, 1};

template <class T, class S>
inline bool xmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool xmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v) os << i << " "; os << '\n';
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (int i = 0; i < (int) v.size(); ++i) is >> v[i];
    return is;
}

using int64 = long long;
using f64 = long double;
 
#ifdef DEBUG 
#include "debug.h"
#else
#define debug(...) 42
#endif

$1

void solveOne() {
    $2
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T --> 0) {
        solveOne();   
    }
    
    return 0;
}