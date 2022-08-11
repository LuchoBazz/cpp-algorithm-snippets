// it only works if the in the vector all the values are different
template <typename T>
vector<int> argsort(const vector<T> &v) {
    vector<int> ids((int) v.size());
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return v[i] < v[j] || (v[i] == v[j] && i < j);
    });
    return ids;
}