// tested: https://cses.fi/problemset/result/4597533/
int64_t n = 100;

// Time Complexity: O(2*sqrt(N))
for(int64_t l = 1; l <= n; ++l) {
    int64_t time = n / l;
    int64_t r = n / time;
    
    // debug(l, r, time);
    l = r;
}

// {N/1, N/2, N/3, ….. ,N/N}
// l=1  r=1  time=100
// l=2  r=2  time=50
// l=3  r=3  time=33
// l=4  r=4  time=25
// l=5  r=5  time=20
// l=6  r=6  time=16
// l=7  r=7  time=14
// l=8  r=8  time=12
// l=9  r=9  time=11
// l=10 r=10 time=10
// l=11 r=11 time=9
// l=12 r=12 time=8
// l=13 r=14 time=7
// l=15 r=16 time=6
// l=17 r=20 time=5
// l=21 r=25 time=4
// l=26 r=33 time=3
// l=34 r=50 time=2
// l=51 r=100 time=1