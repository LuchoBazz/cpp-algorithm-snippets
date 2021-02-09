int zeros_left(int num) {return (num==0)?32:__builtin_clz(num);}
int zeros_right(int num) {return (num==0)?0:__builtin_ctz(num);}
int count_ones(int num) {return __builtin_popcount(num);}
int parity(int num) {return __builtin_parity(num);}
int LSB(int num) {return __builtin_ffs(num);} //  Least Significant Bit [0 if num == 0]
 
int64_t zeros_left(int64_t num) {return (num==0LL)?64LL:__builtin_clzll(num);}
int64_t zeros_right(int64_t num) {return (num==0LL)?0LL:__builtin_ctzll(num);}
int64_t count_ones(int64_t num) {return __builtin_popcountll(num);}
int64_t parity(int64_t num) {return __builtin_parityll(num);}
int64_t LSB(int64_t num) {return __builtin_ffsll(num);} //  Least Significant Bit [0 if number == 0]
 
template<typename T>
int hamming(const T &lhs, const T &rhs) {
    if(is_same<T, int64_t>::value) return __builtin_popcountll(lhs ^ rhs);
    return __builtin_popcount(lhs ^ rhs);
}

// 1LL for 64-bits

// x & 1            : Check if x is odd
// x & (1 << i)     : Check if the i-th bit is HIGH
// x = x | (1<<i)   : Set HIGH i-th bit
// x = x & ~(1<<i)  : Set LOW i-th bit
// x = x ^ (1<<i)   : Flip i-th bit
// x = ~x           : Flip all the bits
// x & -x           : returns the number of the first HIGH bit from right to left (power of 2, not the index)
// log2(x & -x)     : Return position of first bit HIGH from right to left (0-index [..., 3, 2, 1, 0])
// ~x & (x+1)       : Returns the number of the first LOW bit from right to left (power of 2, not the index)
// log2(~x & (x+1)) : Returns position of the first LOW bit from right to left (0-index [..., 3, 2, 1, 0])
// x = x | (x+1)    : Set HIGH of first bit from right to left
// x = x & (x-1)    : Set LOW of first bit from right to left
// x = x & ~y       : Set LOW in x the HIGH bits in y

// Iterates over the indices of the high bits in a mask
/// O(#bits_encendidos)
// for (int x = mask; x; x &= x-1) {
//     int i = __builtin_ctz(x);
// }

// Iterate all the submasks of a mask. (Iterate all submasks of all masks is O(3^n)).
/// O(2^(#bits_encendidos))
// for (int sub = mask; sub; sub = (sub-1)&mask) {
// }
