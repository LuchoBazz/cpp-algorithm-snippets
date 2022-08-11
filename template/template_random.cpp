/**
 * @created     : `!v strftime("%B %d, %Y")`
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define _ << ' ' <<
#define PB push_back
#define SZ(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define overload4(a, b, c, d, e, ...) e
#define for1(a) for(int i = 0; i < int(a); ++i)
#define for2(i, a) for(int i = 0; i < int(a); ++i)
#define for3(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define for4(i, a, b, c) for(int i = int(a); i <= int(b); i += int(c))
#define forn(...) overload4(__VA_ARGS__, for4, for3, for2, for1)(__VA_ARGS__)

using int64 = long long;
 
#ifdef DEBUG 
#include "debug.h"
#else
#define debug(...) 42
#endif

template<typename T>
struct Limits {
    T from;
    T to;
    Limits(T f, T t) : from(f), to(t) {assert(from <= to);}
};

template <typename T>
T random(const T from, const T to) {
    static random_device rdev;
    static default_random_engine re(rdev());

    using dist_type = typename conditional<
        is_floating_point<T>::value,
        uniform_real_distribution<T>,
        uniform_int_distribution<T>
    >::type;

    dist_type uni(from, to);
    return static_cast<T>(uni(re));
}

template<typename T>
T random(Limits<T> limit) {
    return random(limit.from, limit.to);
}

template<typename T>
vector<T> random_permutation(int n, T start = 0) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<T> permutation(n);
    iota(permutation.begin(), permutation.end(), start);
    shuffle(permutation.begin(), permutation.end(), rng);
    return permutation;
}

template<typename T>
vector<T> random_vector(int n, Limits<T> limit) {
    vector<T> values(n);
    for(int i = 0; i < n; ++i) {
        values[i] = random<T>(limit);
    }
    return values;
}

template<typename T> // supported for vector, list and deque
void write(T &&ref, int n=-1, int start=0, string mid=" ", string end_l="\n") {
    if(n < 0) n = (int) ref.size();
    assert(0<=start && 0<=n && start+n<=(int)ref.size());
    auto end_it = next(begin(ref), start+n);
    for(auto it=next(begin(ref), start); it != end_it; it++)
        cout << *it << mid; cout << end_l;
}

template<typename T>
bool is_unique(Limits<T> limits) {
    return limits.from==static_cast<T>(1) && limits.to==static_cast<T>(1);
}

template<typename T, typename F>
void test_cases(Limits<T> test_number, F func) {
    T t = random(test_number);
    if(!is_unique(test_number)) 
        cout << t << endl;
    for(int i = 1; i <= t; ++i)
        func(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    using Type = int64;
    
    Limits<Type> T  {Type(1), Type(1)}; // test cases

    Limits<Type> N  {Type(1), Type(1e5)};
    Limits<Type> Ai {Type(1e18), Type(1e18)+10};
    
    test_cases(T, [&](int test_num) -> void {
        Type n = random(N);
        cout << n << endl;
        vector<Type> v = random_vector<Type>(n, Ai);
        write(v);
    });
    cout.flush();
    return 0;
}