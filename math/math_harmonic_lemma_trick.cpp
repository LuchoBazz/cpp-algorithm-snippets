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
// n=100
// l=1  r=1  time=100  -> 100/1 = 10
// l=2  r=2  time=50   -> 100/2 = 50
// l=3  r=3  time=33   -> 100/3 = 33
// l=4  r=4  time=25   -> 100/4 = 25
// l=5  r=5  time=20   -> 100/5 = 20
// l=6  r=6  time=16   -> 100/6 = 16
// l=7  r=7  time=14   -> 100/7 = 14
// l=8  r=8  time=12   -> 100/8 = 12
// l=9  r=9  time=11   -> 100/9 = 11
// l=10 r=10 time=10   -> 100/10 = 10
// l=11 r=11 time=9   -> 100/11 = 9
// l=12 r=12 time=8   -> 100/12 = 8
// l=13 r=14 time=7   -> 100/13 = 7  and 100/14 = 7
// l=15 r=16 time=6   -> 100/15 = 6  and 100/16 = 6
// l=17 r=20 time=5   -> 100/17 = 5  and 100/18 = 5  and 100/19 = 5 and 100/20 = 5
// l=21 r=25 time=4   -> 100/21 = 4  and 100/22 = 4  and .... and 100/25 = 4
// l=26 r=33 time=3   -> 100/26 = 3  and 100/27 = 3  and .... and 100/33 = 3
// l=34 r=50 time=2   -> 100/34 = 2  and 100/35 = 2  and .... and 100/50 = 2
// l=51 r=100 time=1  -> 100/515 = 1  and 100/52 = 1  and .... and 100/100 = 1