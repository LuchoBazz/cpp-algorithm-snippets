template<typename T, typename U>
T fastpow(T a, U b) {
    assert(0 <= b); T ans = static_cast<T>(1);
    while (b > 0) {
        if (b & 1) ans = ans*a;
        a *= a; b >>= 1;
    }
    return ans;
}

template<typename T,  T MOD>
struct Modular {
    static const T mod = MOD;
    T value; 
    operator int() const { return static_cast<int>(value); }
    operator int64_t() const { return static_cast<int64_t>(value); }
    
    Modular() { value = static_cast<T>(0); }
    T normalize(int64_t num) {
        return static_cast<T>((-MOD < num && num < MOD) ? num : num % MOD); }
    Modular(int64_t num) { value = normalize(num);
        if (value < static_cast<T>(0)) value += MOD; }
    friend bool operator==(const Modular& a, const Modular& b) { 
        return a.value == b.value; }
    friend bool operator!=(const Modular& a, const Modular& b) { 
        return !(a == b); }
    friend bool operator<(const Modular& a, const Modular& b) { 
        return a.value < b.value; }
    friend ostream& operator<<(ostream& os, const Modular& number) {
      return os << static_cast<T>(number); }
    friend istream& operator>>(istream& stream, Modular& number) {
        T tmp; stream >> tmp; number = Modular(tmp);
        return stream; }
    friend string to_string(Modular a) { return to_string(a.value); }
    Modular& operator+=(const Modular& m) { 
        if ((value += m.value) >= MOD) value -= MOD; 
        return *this; }
    Modular& operator-=(const Modular& m) { 
        if ((value -= m.value) < 0) value += MOD; 
        return *this; }
    Modular& operator*=(const Modular& m) { 
        value = int(1LL*value*m.value%MOD); return *this; }
    Modular& operator/=(const Modular& m) { return (*this) *= inverse(m); }
    friend Modular inverse(const Modular& a) {
        assert(a.value != 0); return fastpow(a, MOD-2); }
    Modular operator-() const { return Modular(-value); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    friend Modular operator+(Modular a, const Modular& b) { return a += b; }
    friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
    friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
    friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
};