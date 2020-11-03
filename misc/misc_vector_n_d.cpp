template<typename T>
vector<vector<T>> vector2d(int x1, int x2, T default_value=T()) {
    return vector<vector<T>>(x1, vector<T>(x2, default_value));
}
template<typename T>
vector<vector<vector<T>>> vector3d(int x1, int x2, int x3, T default_value=T()) {
    return vector<vector<vector<T>>>(x1, vector<vector<T>>(x2, vector<T>(x3, default_value)));
}
template<typename T>
vector<vector<vector<vector<T>>>> vector4d(int x1, int x2, int x3, int x4, T default_value=T()) {
    return vector<vector<vector<vector<T>>>>(x1, vector<vector<vector<T>>>(x2, vector<vector<T>>(x3, vector<T>(x4, default_value))));
}