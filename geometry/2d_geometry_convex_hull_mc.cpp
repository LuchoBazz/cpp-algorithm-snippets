// 2d_geometry_polygon

template<typename T>
Polygon<T> convex_hull(Polygon<T> points) {
    int n = int(points.size());
    if(n <= 1) return points;
    vector<Point<T>> hull;
    // Sorting Points
    sort(points.begin(), points.end());
    // it=0: Upper Hull
    // it=1: Lower Hull
    for(int it = 0; it < 2; ++it) {
        int sz = (int) hull.size();
        for(int i = 0; i < n; ++i) {
            // if colineal are needed, use < and remove repeated points
            while((int) hull.size()>=sz+2 && hull[hull.size()-2].orient(hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        // Eliminating repeating points, start and end point
        hull.pop_back();
        reverse(points.begin(), points.end());
    }
    // removing duplicate points
    if(hull.size()==2 && hull[0]==hull[1])
        hull.pop_back();
    return Polygon<T>(hull);
}
// Convex Hull - Monotone Chain
// Time Complexity: O(N*log2(N)), Space Complexity: O(N)
// N: Number of Points