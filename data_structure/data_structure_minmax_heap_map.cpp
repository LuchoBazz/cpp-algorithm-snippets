template <typename T>
struct minmax_heap {
    map<T, int> values;
    int cnt;

    minmax_heap() : cnt(0) {}
    minmax_heap(vector<T> &v) : cnt(0) {
        for(auto &a: v)
            push(a);
    }
    minmax_heap(const minmax_heap<T> &other) {
        values = other.values;
        cnt = other.cnt;
    }

    typename map<T, int>::iterator begin() { return values.begin(); }
    typename map<T, int>::iterator end() { return values.end(); }
    
    void push(T &value) { values[value]++; cnt++; }

    bool erase(T &value) {
        auto it = values.find(value);
        if(it != values.end()) {
            (*it).second--;
            if((*it).second == 0)
                values.erase(it);
            cnt--;
            return true;
        }
        return false;
    }

    T get_max() {
        assert(!empty());
        return (*values.rbegin()).first;
    }

    T get_min() {
        assert(!empty());
        return (*values.begin()).first;
    }
    
    int count_max() {
        return values[get_max()];
    }
    
    int count_min() {
        return values[get_min()];
    }
    
    int count(int value) {
        auto it = values.find(value);
        if(it != values.end())
            return (*it).second;
        return 0;
    }

    T pop_max() {
        assert(!empty());
        T to_return = get_max();
        auto it = --values.end();
        (*it).second--;
        if((*it).second == 0)
            values.erase(it);
        cnt--;
        return to_return;
    }

    T pop_min() {
        assert(!empty());
        T to_return = get_min();
        auto it = values.begin();
        (*it).second--;
        if((*it).second == 0)
            values.erase(it);
        cnt--;
        return to_return;
    }

    bool empty() {return values.empty();}
    int size() const { return cnt;}
    void clear() { values.clear(); }

    void swap(minmax_heap<T>& other) noexcept {
        values.swap(other.values);
    }
    bool operator == (const minmax_heap<T> &other) const { return values==other.values;}
    bool operator != (const minmax_heap<T> &other) const { return !(*this == other);}
};