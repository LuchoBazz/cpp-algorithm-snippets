#define zeros_left(number)  ((number == 0)?32:__builtin_clz(number))
#define zeros_right(number) ((number == 0)?0:__builtin_ctz(number))
#define count_ones(number)  (__builtin_popcount(number))
#define parity(number)      (__builtin_parity(number))
#define LSB(number)         (__builtin_ffs(number)) //  Least Significant Bit [0 if number == 0]

#define zeros_left64(number)  ((number == 0LL)?64:__builtin_clzll(number))
#define zeros_right64(number) ((number == 0LL)?0:__builtin_ctzll(number))
#define count_ones64(number)  (__builtin_popcountll(number))
#define parity64(number)      (__builtin_parityll(number))
#define LSB64(number)         (__builtin_ffsll(number)) //  Least Significant Bit [0 if number == 0]

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
