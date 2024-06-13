template <typename T> // To merge two vectors, the answer is an ordered vector
void merge_vector(vector<T> &big, vector<T> &small) {
    int n = (int)big.size(), m = (int)small.size();
    if (m > n)
        swap(small, big);
    if (!is_sorted(big.begin(), big.end()))
        sort(big.begin(), big.end());
    if (!is_sorted(small.begin(), small.end()))
        sort(small.begin(), small.end());
    vector<T> aux;
    merge(small.begin(), small.end(), big.begin(), big.end(), aux.begin());
    big = move(aux);
}
