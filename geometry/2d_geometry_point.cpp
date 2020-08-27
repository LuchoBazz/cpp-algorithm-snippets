#define PI   3.141592653589793238462643383279502884L // (2*acos(0.0))
#define eps  1e-9

typedef long double floating_t;
typedef int64_t TP;

struct Point {
    TP x;
    TP y;
    
    Point operator + (Point p) { return {x+p.x, y+p.y};}
    Point operator - (Point p) { return {x-p.x, y-p.y};}
    Point operator * (Point p) { return {x*p.x-y*p.y, x*p.y+y*p.x};}
    Point operator * (TP p) { return {x*p, y*p};}
    Point operator / (TP p) { return {x/p, y/p};} // only for floating point
    bool operator == (Point &p) const { return x==p.x && y == p.y;}
    bool operator != (Point &p) const { return !(*this == p);}
    bool operator < (Point &p) const { return x < p.x || (x == p.x && y < p.y);}
    bool operator > (Point &p) const { return x > p.x || (x == p.x && y > p.y);}
    
    // bool operator < (const Point &p) const { return y<p.y || (y==p.y && x < p.x); }
    // bool operator > (const Point &p) const { return y>p.y || (y==p.y && x > p.x); }
    
    // Already in Complex
    TP norm() { return x*x + y*y;}
    TP norm(Point p) { return abs(p.x-x)*abs(p.x-x) + abs(p.y-y)*abs(p.y-y);}
    
    floating_t arg()  { return atan2(y, x);}
    TP dot(Point p) { return x*p.x + y*p.y; }
    TP cross(Point p) { return x*p.y - y*p.x; }
    TP orient(Point b, Point c) { return (b-*this).cross(c-*this); }
    
    // Distances
    // Euclidean Distance
    floating_t eucl_dist()  { return sqrt(norm()); }
    floating_t eucl_dist(Point p)  { return sqrt(norm(p)); }
    
    // Manhattan Distance
    TP man_dist() { return abs(x) + abs(y);}
    TP man_dist(Point p) { return abs(x-p.x) + abs(y-p.y);}
    
    // Chebyshev Distance
    TP ch_dist() { return max(abs(x), abs(y));}
    TP ch_dist(Point p) { return max(abs(x-p.x), abs(y-p.y));}
};

// Aditional Functions
int cmp(floating_t a, floating_t b) {
    return (a + eps < b ? -1 :(b + eps < a ? 1 : 0));
}

string to_string(Point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}