// Perimeter of a Polygon
floating_t perimeter(vector<Point> points) {
    int n = int(points.size());
    floating_t ans = 0.0;
    for(int i = 0; i < n; ++i) {
        ans += points[i].eucl_dist(points[(i + 1) % n]);
    }
    return ans;
}
// Time Complexity: O(N), Space Complexity: O(1)
// N: Number of Points