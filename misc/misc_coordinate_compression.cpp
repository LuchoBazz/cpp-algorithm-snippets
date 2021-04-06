template<typename T>
struct CoordinateCompression {
    
    vector<T> coord;
    
    CoordinateCompression(vector<T> &v) {
        coord = vector<T>(v);
        if(!is_sorted(coord.begin(), coord.end())) {
            sort(coord.begin(), coord.end());
        }
    }
    
    int get_index(T value) {
        return lower_bound(coord.begin(), coord.end(), value)-coord.begin();
    }
};

template<typename T>
using CC = CoordinateCompression<T>;