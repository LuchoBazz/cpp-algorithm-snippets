template <typename T>
struct minmax_heap {
    multiset<T> values;

    minmax_heap() {}
    minmax_heap(vector<T> &v) {
        for(auto &a: v)
            values.insert(a);
    }
    minmax_heap(const minmax_heap<T> &other) {
        values = other.values;
    }

    typename multiset<T>::iterator begin() { return values.begin(); }
    typename multiset<T>::iterator end() { return values.end(); }
    
    void push(T value) {
        values.insert(value);
    }

    bool erase(T value) {
        auto it = values.find(value);
        if(it != values.end()) {
            values.erase(it);
            return true;
        }
        return false;
    }

    T get_max() {
        assert(!empty());
        return *values.rbegin();
    }

    T get_min() {
        assert(!empty());
        return *values.begin();
    }

    T pop_max() {
        assert(!empty());
        T to_return = get_max();
        values.erase(--values.end());
        return to_return;
    }

    T pop_min() {
        assert(!empty());
        T to_return = get_min();
        values.erase(values.begin());
        return to_return;
    }

    bool empty() {return values.empty();}
    int size() const {return (int) values.size();}
    void clear() { values.clear(); }

    void swap(minmax_heap<T>& other) noexcept {
        values.swap(other.values);
    }
    bool operator == (const minmax_heap<T> &other) const { return values==other.values;}
    bool operator != (const minmax_heap<T> &other) const { return !(*this == other);}
};