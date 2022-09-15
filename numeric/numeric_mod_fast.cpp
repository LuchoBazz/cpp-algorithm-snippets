// inline int add(int a, int b, const int& mod) { return (a+b>=mod)? a+b-mod : a+b; }
// inline int sub(int a, int b, const int& mod) { return (a-b<0)? a-b+mod : a-b; }
// inline int mul(int a, int b, const int& mod) { return (1LL*a*b)%mod; }

const int md = 1e9 + 7;

inline int add(int a, int b) { return (a+b>=md)? a+b-md : a+b; }
inline int sub(int a, int b) { return (a-b<0)? a-b+md : a-b; }
inline int mul(int a, int b) { return (1LL*a*b)%md; }