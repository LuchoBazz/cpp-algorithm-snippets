// Area of a Polygon
floating_t area(vector<Point> points, bool sign = false) {
    int n = points.size();
    floating_t ans = 0.0;
    for(int i = 0; i < n; ++i) {
        ans += points[i].cross(points[(i + 1) % n]);
    }
    ans /= 2.0;
    // ans >= 0 (counter-clock wise): Sentido Antihorario
    // ans < 0  (clockwise): Agujas del Reloj
    return (!sign)? abs(ans):ans;
}