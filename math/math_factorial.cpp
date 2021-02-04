template<typename T>
class Factorial {
public:
    int n;
    vector<T> fact;
    Factorial() : n(-1) {}
    
    Factorial(int mx) : fact(mx+1), n(mx+1) {
        assert(1 <= mx);
        fact[0] = static_cast<T>(1);
        fact[1] = static_cast<T>(1);
        for(int num = 2; num <= mx; ++num) {
            fact[num] = fact[num-1]*static_cast<T>(num);
        }
    }
    T& operator[](int idx) {
        assert(0 <= idx && idx < n);
        return fact[idx];
    }
};