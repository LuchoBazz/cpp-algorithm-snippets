template<typename T>
T inverse(T a, T m) {
    a = (a + m) % m;
    if (a < static_cast<T>(a)) a += m;
    T b = m, u = 0, v = 1;
    while (static_cast<T>(a) > 0) {
        T t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == static_cast<T>(1)); // zero division
    if (u < static_cast<T>(0)) u += m;
    if(b != static_cast<T>(1)) u = -1;
    return u;
}

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}

    template <typename U>
    Modular(U x) {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }

    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value)); 
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }
    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
    template <typename U> Modular<U> abs(const Modular<U>& v) { return v; }

    template <typename U> friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U> friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U> friend bool operator<=(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U> friend bool operator>(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U> friend bool operator>=(const Modular<U>& lhs, const Modular<U>& rhs);
    template <typename U> friend istream& operator>>(istream& stream, Modular<U>& number);

    operator int() {return (int) value;}
    operator int64_t() {return (int64_t) value;}
private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
template <typename T, typename U> bool operator<(const Modular<T>& lhs, U rhs) { return lhs < Modular<T>(rhs); }
template <typename T, typename U> bool operator<(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) < rhs; }

template <typename T> bool operator<=(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value <= rhs.value; }
template <typename T, typename U> bool operator<=(const Modular<T>& lhs, U rhs) { return lhs <= Modular<T>(rhs); }
template <typename T, typename U> bool operator<=(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) <= rhs; }

template <typename T> bool operator>(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value > rhs.value; }
template <typename T, typename U> bool operator>(const Modular<T>& lhs, U rhs) { return lhs > Modular<T>(rhs); }
template <typename T, typename U> bool operator>(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) > rhs; }

template <typename T> bool operator>=(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value >= rhs.value; }
template <typename T, typename U> bool operator>=(const Modular<T>& lhs, U rhs) { return lhs >= Modular<T>(rhs); }
template <typename T, typename U> bool operator>=(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) >= rhs; }

template<typename T, typename U>
Modular<T> fastpow(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
    return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int__;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& MOD = VarMod::value;
using Mint = Modular<VarMod>;
*/

const int MOD = int(1e9) + 7;

// Modular Integer -> Mint
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

bool is_zero_division(Mint &a) {
    using T = Mint::Type; // don't forget to remove assert in reverse
    return inverse(static_cast<T>(a), MOD) < static_cast<T>(0);
}
