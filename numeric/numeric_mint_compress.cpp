template<typename T>
T inverse(T a, T m) {
    a = (a + m) % m; if (a < static_cast<T>(a)) a += m;
    T b = m, u = 0, v = 1;
    while (static_cast<T>(a) > 0) {
        T t = b / a; b -= t * a; swap(a, b); u -= t * v; swap(u, v); }
    assert(b == static_cast<T>(1)); // zero division
    if (u < static_cast<T>(0)) u += m;
    if(b != static_cast<T>(1)) u = -1;
    return u;}

template<typename Type>
struct Modular {
    using T = typename decay<decltype(Type::value)>::type;
    const T MOD = Type::value;
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
        T tmp; stream >> tmp; number = Modular(tmp);return stream; }
    friend string to_string(Modular a) { return to_string(a.value); }
    Modular& operator+=(const Modular& m) { 
        if ((value += m.value) >= MOD) value -= MOD; return *this; }
    Modular& operator-=(const Modular& m) { 
        if ((value -= m.value) < 0) value += MOD; return *this; }
    Modular& operator*=(const Modular& m) { 
        value = static_cast<T>(1LL*value*m.value%MOD); return *this; }
    Modular& operator/=(const Modular& m) { return (*this) *= inverse(m); }
    friend Modular inverse(const Modular& a) {
        assert(a.value != 0); return inverse(a.value, Type::value); }
    Modular operator-() const { return Modular(-value); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    friend Modular operator+(Modular a, const Modular& b) { return a += b; }
    friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
    friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
    friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
};
// using ModType = int;
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& MOD = VarMod::value;
// using Mint = Modular<VarMod>;
const int MOD = int(1e9+7); 
// Modular Integer -> Mint
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;
bool is_zero_division(Mint &a) {
    using T = Mint::T; // don't forget to remove assert in reverse
    return inverse(static_cast<T>(a), MOD) < static_cast<T>(0);}
