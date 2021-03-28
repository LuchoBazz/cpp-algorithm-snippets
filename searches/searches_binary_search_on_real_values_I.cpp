double eps = 1e-9;

double n = inf;
double low = 0.0, high = n, mid;

while ((high - low) > eps) {
    mid = double(high + low) / 2.0;
    if(!ok(mid)) {
        low = mid;
    } else {
        high = mid;
    }
}
if(ok(low)) {
    
} else {
    
}