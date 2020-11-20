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