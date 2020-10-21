template<typename T>
class Polygon {
    vector<Point<T>> points;
public:
    Polygon(){}
    Polygon(int n) : points(n) {}
    Polygon(vector<Point<T>> pts) : points(pts.begin(), pts.end()) {}
    typename vector<Point<T>>::iterator begin() { return points.begin(); }
    typename vector<Point<T>>::iterator end() { return points.end(); }
    int size() { return int(points.size()); }
    Point<T>& operator [] (int i) { return points[i]; }
    void add(Point<T> point) {
        points.push_back(point);
    }
    void delete_repetead() {
        // Time Complexity: O(N)
        vector<Point<T>> aux;
        sort(points.begin(), points.end());
        for(Point<T> &pt : points) {
            if(aux.empty() || aux.back() != pt) {
                aux.push_back(pt);
            }
        }
        points.swap(aux);
    }
};

template<typename T>
string to_string(Polygon<T> p) {
    vector<Point<T>> points(p.begin(), p.end());
    return to_string(points);
}

template<typename T>
using polygon = Polygon<T>;