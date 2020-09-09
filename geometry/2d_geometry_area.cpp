// Area of a Polygon
template<typename T>
floating_t area(Polygon<T> points, bool sign = false) {
    int n = int(points.size());
    floating_t ans = 0.0;
    for(int i = 0; i < n; ++i) {
        ans += points[i].cross(points[(i + 1) % n]);
    }
    ans /= 2.0;
    // ans >= 0 (counter-clock wise): Sentido Antihorario
    // ans < 0  (clockwise): Agujas del Reloj
    return (!sign)? abs(ans):ans;
}
// Time Complexity: O(N), Space Complexity: O(1)
// N: Number of Points