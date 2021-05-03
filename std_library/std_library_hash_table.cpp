#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using __gnu_pbds::gp_hash_table;

// random_init

#define PI   3.141592653589793238462643383279502884L // acos(-1);

struct chash { 
    // use most bits rather than just the lowest ones
    const uint64_t C = uint64_t(2e18*PI)+71; // large odd number
    const int RANDOM = random<int>(0, INT_MAX-1);
    int64_t operator()(int64_t x) const { // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
// unordered_map<K, V, chash>;

template<class K, class V, typename Hash = chash>
using hash_table = gp_hash_table<K, V, Hash>;
// don't forget to use the resize method for a constant factor speedup.
// usage:
// hash_table<int, int> mp({}, {}, {}, {}, {1<<19});

template<class K,class V>
V get(hash_table<K, V>& mp, K target) {
    auto it = mp.find(target);
    return it == end(mp) ? 0 : it->second;
}