#define PI   3.141592653589793238462643383279502884L // acos(-1);
#define E    2.718281828459045235360287471352662497L
#define eps  1e-9

template<typename T>
int cmp(const T &a, const T &b) {
    return ( (a + eps < b)? -1 :( (b + eps < a )? 1 : 0) );
}