/**
 * Description: hashing is a known way to convert a string to an integer, in
 * order to have substring comparisons efficiently Time: n: string size
 *     * build: O(n)
 *     * query: O(1)
 * Source: t.ly/VZdC String/Hashing.cpp
 * Verification: t.ly/xaRc
 */

// 1000234999, 1000567999, 1000111997, 1000777121
const int MODS[] = {1001864327, 1001265673};

inline int add(int a, int b, const int &mod) {
    return (a + b >= mod) ? a + b - mod : a + b;
}
inline int sub(int a, int b, const int &mod) {
    return (a - b < 0) ? a - b + mod : a - b;
}
inline int mul(int a, int b, const int &mod) { return (1LL * a * b) % mod; }

class HashInt {
  public:
    int first;
    int second;
    HashInt(int a, int b) : first(a), second(b) {}
    HashInt(int a) : first(a), second(a) {}
    inline friend bool operator==(const HashInt &a, const HashInt &b) {
        return a.first == b.first && a.second == b.second;
    }
    inline friend bool operator!=(const HashInt &a, const HashInt &b) {
        return a.first != b.first && a.second != b.second;
    }
    inline friend HashInt operator+(const HashInt &a, const HashInt &b) {
        return HashInt{add(a.first, b.first, MODS[0]),
                       add(a.second, b.second, MODS[1])};
    }
    inline friend HashInt operator-(const HashInt &a, const HashInt &b) {
        return HashInt{sub(a.first, b.first, MODS[0]),
                       sub(a.second, b.second, MODS[1])};
    }
    inline friend HashInt operator*(const HashInt &a, const HashInt &b) {
        return HashInt{mul(a.first, b.first, MODS[0]),
                       mul(a.second, b.second, MODS[1])};
    }
    operator int64_t() { return (int64_t(first) << 32) | int64_t(second); }
};
using hash_int = HashInt;

const HashInt BASE(256), ZERO(0), ONE(1);
template <class T> struct RollingHashing {
    int n;
    vector<HashInt> code;
    vector<HashInt> base;

    RollingHashing(const T &s) {
        n = (int)s.size();
        base.resize(n + 1, HashInt(0));
        base[0] = ONE;
        for (int i = 1; i <= n; i++)
            base[i] = base[i - 1] * BASE;

        code.resize(n + 1, HashInt(0));
        code[0] = ZERO;
        for (int i = 1; i < (int)code.size(); ++i)
            code[i] = code[i - 1] * BASE + HashInt(s[i - 1]);
    }
    inline int64_t query(int left, int right) {
        assert(0 <= left && left <= right && right < n);
        return int64_t(code[right + 1] - code[left] * base[right - left + 1]);
    }
};

template <class T> using hashing = RollingHashing<T>;
// Usage:
//    string s = "Hello World":
//    hashing<string> h(s);
//    int64_t val = h.query(l, r);
//    h1.query(l1, r1) == h2.query(l2, r2);

// Check palindrome: from - to
// auto hash1 = hash.query(from, to);
// auto hash2 = hash_reverse.query(n-to-1, n-from-1);
// hash1 == hash2
