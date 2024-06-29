// Taken from mcqueencin (Oscar Sierra) library and modified
template <int64_t MD> struct mint_t {
    int64_t m;
    mint_t(){};
    mint_t(const int64_t &o) : m(o){};
    mint_t operator*(const mint_t &o) const {
        return 1LL * ((m % MD) * (o.m % MD)) % MD;
    };
    mint_t operator+(const mint_t &o) const {
        return m + o.m < MD ? m + o.m : m + o.m - MD;
    }
    mint_t operator-(const mint_t &o) const {
        return m - o.m >= 0 ? m - o.m : m - o.m + MD;
    }
    mint_t operator^(int64_t e) const {
        if (e == 0)
            return 1;
        mint_t t = *this ^ (e / 2);
        if (e & 1)
            return t * t * (*this);
        return t * t;
    }
    mint_t operator!() const { return *this ^ (MD - 2); }
    mint_t operator/(const mint_t &b) const { return *this * !b; };
    friend std::ostream &operator<<(std::ostream &os, const mint_t &a) {
        return os << a.m;
    }
    friend std::istream &operator>>(std::istream &is, mint_t &a) {
        int64_t val;
        is >> val;
        a = mint_t(val);
        return is;
    }
};

const int64_t MD = 1e9 + 7;

using mint = mint_t<MD>;
const mint ONE_mi = mint(1);
const mint ZERO_mi = mint(0);

// usage:
// mint X(...), N(...);
// mint pw = X ^ N.m;
