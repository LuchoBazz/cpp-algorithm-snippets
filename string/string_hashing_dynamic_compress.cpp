/**
 * Description: hashing is a known way to convert a string to an integer, in order to have substring comparisons efficiently
 * Time:
 *      n: string size
 *     * build: O(n*log2(n))
 *     * modify, query 1 and 2, set: O(log2(n))
 * Source: t.ly/IiwQ /hashing_bit.cpp
 * Verification: t.ly/EJzF
 */

// 1000234999, 1000567999, 1000111997, 1000777121
const int MODS[] = { 1001864327, 1001265673 };
 
inline int add(int a, int b, const int& mod) { return (a+b>=mod)? a+b-mod : a+b; }
inline int sub(int a, int b, const int& mod) { return (a-b<0)? a-b+mod : a-b; }
inline int mul(int a, int b, const int& mod) { return (1LL*a*b)%mod; }

template<typename T, typename U>
T fastpow(T a, U b, T mod) {
    assert(0 <= b);
    T answer = static_cast<T>(1);
    while (b > 0) {
        if (b & 1)
            answer = mul(answer, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return answer;
}
 
class HashInt {
public:
    int first;
    int second;
    HashInt(int a, int b) : first(a), second(b) {}
    HashInt(int a) : first(a), second(a) {}
    inline friend bool operator==(const HashInt &a,  const HashInt &b) {
        return a.first==b.first&&a.second==b.second;
    }
    inline friend bool operator!=(const HashInt &a,  const HashInt &b) {
        return a.first!=b.first&&a.second!=b.second;
    }
    inline friend HashInt operator+(const HashInt &a,  const HashInt &b) {
        return HashInt{add(a.first, b.first, MODS[0]), add(a.second, b.second, MODS[1])};
    }
    inline friend HashInt operator-(const HashInt &a,  const HashInt &b) {
        return HashInt{sub(a.first, b.first, MODS[0]), sub(a.second, b.second, MODS[1])};
    }
    inline friend HashInt operator*(const HashInt &a,  const HashInt &b) {
        return HashInt{mul(a.first, b.first, MODS[0]), mul(a.second, b.second, MODS[1])};
    }
    inline HashInt inverse() {
        return HashInt{fastpow(first, MODS[0]-2, MODS[0]), fastpow(second, MODS[1]-2, MODS[1])};
    }
    operator int64_t() {
        return (int64_t(first)<<32)|int64_t(second);
    }
};
using hash_int = HashInt;

const int BASE_F=256, BASE_S=256;
const HashInt BASE(BASE_F, BASE_S), ZERO(0), ONE(1);
const HashInt INV_BASE=HashInt(BASE_F, BASE_S).inverse();

template <class T>
struct RollingHashing {
    int n;
    string S;
    
    vector<HashInt> base;
    vector<HashInt> inv_base;
    vector<HashInt> tree;
 
    RollingHashing(const T &s) : S(s) {
        n = (int) s.size();
        tree.resize(n+1, HashInt(0));
        base.resize(n+1, HashInt(0));
        inv_base.resize(n+1, HashInt(0).inverse());
        
        base[0] = ONE;
        inv_base[0] = ONE;
        for(int i = 1; i <= n; i++)
            base[i] = base[i-1]*BASE,
            inv_base[i] = inv_base[i-1]*INV_BASE;

        for (int i = 0; i < (int) tree.size(); ++i)
            modify(i, S[i]);
    }
private:
    inline void modify(int index, HashInt value) {
        HashInt val = base[index]*value;
        index += 1;
        while(index <= n) {
            tree[index] = tree[index] + val;
            index += index & (-index);
        }
    }
    
    inline HashInt query(int index) {
        index += 1;
        HashInt ans(0);
        while(index > 0) {
            ans = ans + tree[index];
            index -= index & (-index);
        }        
        return ans;
    }
public:
    inline void set(int index, char value) {
        int delta1 = (MODS[0] + value - S[index]) % MODS[0];
        int delta2 = (MODS[1] + value - S[index]) % MODS[1];
        S[index] = value;
        modify(index, HashInt(delta1, delta2));
    }
        
    inline int64_t query(int left, int right) {
        assert(0 <= left && left <= right && right < n);
        return int64_t((query(right) - query(left))*inv_base[left]);
    }
};
 
template <class T>
using hashing = RollingHashing<T>;

// Usage:
//    string s = "Hello World":
//    hashing<string> h(s);
//    int64_t val = h.query(l, r);
//    h1.query(l1, r1) == h2.query(l2, r2);
//    h1.set(0, 'a');
