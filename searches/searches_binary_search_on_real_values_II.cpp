double n = inf;
double low = 0.0, high = n, mid;

int iter = 0;
while(iter < 300) {
    mid = double(high + low) / 2.0;
    if(!ok(mid)) {
        low = mid;
    } else {
        high = mid;
    }
    iter++;
}
if(ok(low)) {
    
} else {
    
}