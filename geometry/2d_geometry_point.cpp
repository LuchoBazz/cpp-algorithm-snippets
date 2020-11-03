typedef long double floating_t;

template<typename T>
struct Point {
    T x;
    T y;

    Point<T> operator + (Point<T> p) { return {x+p.x, y+p.y};}
    Point<T> operator - (Point<T> p) { return {x-p.x, y-p.y};}
    Point<T> operator * (Point<T> p) { return {x*p.x-y*p.y, x*p.y+y*p.x};}
    Point<T> operator * (T p) { return {x*p, y*p};}
    Point<T> operator / (T p) { return {x/p, y/p};} // only for floating point
    bool operator == (Point<T> &p) const { return x==p.x && y == p.y;}
    bool operator != (Point<T> &p) const { return !(*this == p);}
    bool operator < (Point<T> &p) const { return x < p.x || (x == p.x && y < p.y);}
    bool operator > (Point<T> &p) const { return x > p.x || (x == p.x && y > p.y);}
    
    // bool operator < (const Point<T> &p) const { return y<p.y || (y==p.y && x < p.x); }
    // bool operator > (const Point<T> &p) const { return y>p.y || (y==p.y && x > p.x); }
    
    // Already in Complex
    T norm() { return x*x + y*y;}
    T norm(Point<T> p) { return abs(p.x-x)*abs(p.x-x) + abs(p.y-y)*abs(p.y-y);}
    
    floating_t arg()  { return atan2(y, x);}
    T dot(Point<T> p) { return x*p.x + y*p.y; }
    T cross(Point<T> p) { return x*p.y - y*p.x; }
    T orient(Point<T> b, Point<T> c) { return (b-*this).cross(c-*this); }
    
    // Distances
    // Euclidean Distance
    floating_t eucl_dist()  { return sqrt(norm()); }
    floating_t eucl_dist(Point<T> p)  { return sqrt(norm(p)); }
    
    // Manhattan Distance
    T man_dist() { return abs(x) + abs(y);}
    T man_dist(Point<T> p) { return abs(x-p.x) + abs(y-p.y);}
    
    // Chebyshev Distance
    T ch_dist() { return max(abs(x), abs(y));}
    T ch_dist(Point<T> p) { return max(abs(x-p.x), abs(y-p.y));}
};

template<typename T>
string to_string(Point<T> p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

template<typename T>
using point = Point<T>;