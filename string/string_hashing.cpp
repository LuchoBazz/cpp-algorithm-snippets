// 1000567999, 1000111997, 1000777121
vector<int> MODS = { 1001864327, 1001265673, 1000234999};

int add(int a, int b, int mod) { return ((a%mod)+(b%mod)) % mod; }
int sub(int a, int b, int mod) { return ((a%mod)-(b%mod)+mod)%mod; }
int mul(int a, int b, int mod) { return (1LL*(a%mod)*(b%mod))%mod; }

template<vector<int> &MD>
class HashInt {
    friend HashInt<MD> operator_hash(const HashInt<MD> &a,  const HashInt<MD> &b, const function<int(int, int, int)> &F) {
        int n = (int) MD.size();
        HashInt<MD> res(vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
            res[i] = F(a.values[i], b.values[i], MD[i]);
        return res;
    }
public:
    vector<int> values;
    int sz;
    HashInt(vector<int> v) {
        assert((int) v.size() == (int) MD.size());
        sz = (int) MD.size();
        values = v;
    }
    HashInt(int value) {
        values.resize((int) MD.size(), value);
        sz = (int) MD.size();
    }
    int& operator [] (int i) { assert(0 <= i && i < sz); return values[i]; }
    friend bool operator==(const HashInt<MD> &lhs,  const HashInt<MD> &rhs) {
        return lhs.values == rhs.values;
    }
    friend HashInt<MD> operator+(const HashInt<MD> &lhs,  const HashInt<MD> &rhs) {
        return operator_hash(lhs, rhs, add);
    }
    friend HashInt<MD> operator-(const HashInt<MD> &lhs,  const HashInt<MD> &rhs) {
        return operator_hash(lhs, rhs, sub);
    }
    friend HashInt<MD> operator*(const HashInt<MD> &lhs,  const HashInt<MD> &rhs) {
        return operator_hash(lhs, rhs, mul);
    }
};

using hash_int = HashInt<MODS>;
const hash_int BASE(256), ZERO(0), ONE(1);

template <class T>
struct RollingHashing {
    vector<hash_int> code;
    vector<hash_int> base;
    
    RollingHashing(const T &t) {
        base.resize((int)t.size()+1, hash_int(vector<int>(hash_int(0).sz, 0)));
        base[0] = ONE;
        for(int i = 1; i <= (int)t.size(); i++)
            base[i] = base[i-1]*BASE;
        
        code.resize((int) t.size()+1, hash_int(vector<int>(hash_int(0).sz, 0)));
        code[0] = ZERO;
        for (int i = 1; i < code.size(); ++i)
            code[i] = code[i-1]*BASE + hash_int((int)t[i-1]);
    }
    hash_int query(int l, int r) {
        return code[r+1] - code[l]*base[r-l+1];
    }
};

template <class T>
using hashing = RollingHashing<T>;
// Usage:
//    string s = "Hello World":
//    hashing<string> h(s);
//    hash_int val = h.query(l, r);
//    h.query(l1, r1) == h1.query(l2, r2);
