#define zeros_left(number)  __builtin_clz(number) // number != 0
#define zeros_right(number) __builtin_ctz(number)
#define count_ones(number)  __builtin_popcount(number)
#define parity(number)      __builtin_parity(number)