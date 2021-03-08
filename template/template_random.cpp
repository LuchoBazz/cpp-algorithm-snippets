/**
 * @created     : `!v strftime("%B %d, %Y")`
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define finally(value) {cout << (value) << endl; return;}
using int64 = int64_t;

template<typename T>
struct Limits {
    T from;
    T to;
    Limits(T f, T t) : from(f), to(t) {assert(from <= to);}
};

random_device rd;
mt19937_64 gen(rd());

template<typename T>
T random(T from, T to) {
    if constexpr (is_integral<T>::value) {
        return uniform_int_distribution<T>(from, to)(gen);
    } else if constexpr (is_floating_point<T>::value) {
        return uniform_real_distribution<T>(from, to)(gen);
    }
    return uniform_int_distribution<T>(from, to)(gen);
}

template<typename T>
T random(Limits<T> limit) {
    return random(limit.from, limit.to);
}

template<typename T>
vector<T> random_permutation(int n, T start = 0) {
    vector<T> permutation(n);
    iota(permutation.begin(), permutation.end(), start);
    shuffle(permutation.begin(), permutation.end(), gen);
    return permutation;
}

template<typename T>
vector<T> random_vector(int n, Limits<T> limit) {
    vector<T> values(n);
    for(int i = 0; i < n; ++i) {
        values[i] = random(limit);
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

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    using Type = int64;
    
    Limits<Type> T  {Type(1), Type(1)}; // test cases

    Limits<Type> N  {Type(1), Type(1e5)};
    Limits<Type> Ai {Type(1e18), Type(1e18)+10};
    
    test_cases(T, [&](int test_num) -> void {
        Type n = random(N);
        cout << n << endl;
        vector<Type> v = random_vector(n, Ai);
        write(v);
    });
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