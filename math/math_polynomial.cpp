
// math_fft

template<typename T>
class Polynomial {
    void check_data_types() {
        assert(is_integral<T>::value || is_floating_point<T>::value);
    }
public:

    vector<T> poly;

    Polynomial(int n) : poly(n) {check_data_types();}
    Polynomial(int n, T initialize) : poly(n, initialize) {check_data_types();}
    Polynomial(const vector<T> &p) : poly(p) {check_data_types();}

    int degree() {
        // degree of the polynomial
        return int(poly.size()) - 1;
    }

    Polynomial<T> scale(int n) {
        // Multiply polynomial p(x) with x^n.
        // If n is negative, poly p(x) is divided with x^n, and remainder is
        // discarded (truncated division).
        Polynomial<T> ans;
        ans.poly.reserve(2*n);
        if(n >= 0) {
            ans.poly.insert(ans.poly.end(), poly.begin(), poly.end());
            for(int i = 0; i < n; ++i) {
                ans.poly.push_back(0);
            }
        } else {
            ans.poly.insert(ans.poly.end(), poly.begin(), poly.begin() + n);
        }
        return ans;
    }

    Polynomial<T> extend(int d) {
        // Extend list p representing a polynomial p(x) to
        // match polynomials of degree d-1.
        int sz = d-int(poly.size());
        if(sz <= 0) return *this;
        Polynomial<T> ans(sz, T(0));
        for(int i = 0; i < int(poly.size()); ++i) {
            ans.poly.push_back(poly[i]);
        }
        poly.swap(ans.poly);
        return *this;
    }

    Polynomial<T> norm() {
        // Normalize the polynomial p(x) to have a non-zero most significant
        // coefficient.
        // [0, 0, 3, 1] -> [3, 1]
        vector<T> ans;
        for(int i = 0; i < int(poly.size()); ++i){
            if(poly[i] != T(0)) {
                ans.reserve(int(poly.size()) - i);
                for(int j = i; j < int(poly.size()); ++j){
                    ans.push_back(poly[j]);
                }
                return ans;
            }
        }
        return Polynomial<T>(ans);
    }

    Polynomial<T> operator*(T number) {
        // Multiply polynomial p(x) with scalar (constant) a.
        for(int i = 0; i < int(poly.size()); ++i){
            poly[i] *= number;
        }
        return *this;
    }

    Polynomial<T> operator+(const Polynomial<T> &other) {
        // Add polynomials f(x) and g(x).
        int n = int(poly.size());
        int m = int(other.poly.size());
        int sz = max(n, m);
        Polynomial<T> fx(poly);
        Polynomial<T> gx(other.poly);
        Polynomial<T> ans(sz, 0);
        fx.extend(sz);
        gx.extend(sz);
        for(int i = 0; i < sz; ++i){
            ans.poly[i] = fx.poly[i] + gx.poly[i];
        }
        return ans;
    }

    Polynomial<T> operator-(const Polynomial<T> &other) {
        // Subtract polynomials f(x) and g(x).
        int n = int(poly.size());
        int m = int(other.poly.size());
        int sz = max(n, m);
        Polynomial<T> fx(poly);
        Polynomial<T> gx(other.poly);
        Polynomial<T> ans(sz, 0);
        fx.extend(sz);
        gx.extend(sz);
        for(int i = 0; i < sz; ++i){
            ans.poly[i] = fx.poly[i] - gx.poly[i];
        }
        return ans;
    }

    Polynomial<T> operator*(Polynomial<T> &other) {
        // Multiply polynomials f(x) and g(x) with FFT.
        vector<complex<double>> fx(poly.rbegin(), poly.rend());
        vector<complex<double>> gx(other.poly.rbegin(), other.poly.rend());
        int n = 1;
        while (n < int(poly.size()) + int(other.poly.size())) n <<= 1;
        fx.resize(n);
        gx.resize(n);

        fft(fx);
        fft(gx);
        for (int i = 0; i < n; i++) fx[i] *= gx[i];
        fft(fx, true);

        vector<T> result(n);
        for (int i = 0; i < n; i++) result[i] = round(fx[i].real());
        reverse(result.begin(), result.end());
        Polynomial<T> ans(result);
        return ans.norm();
    }
};

using Poly = Polynomial<int>;
// using Poly = Polynomial<int64_t>;
