template <typename T>
struct priority_deque {
    multiset<T> values;

    priority_deque() {}
    priority_deque(vector<T> &v) {
        for(auto &a: v)
            values.insert(a);
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

    T back() { // returns the maximum element in the deque
        assert(!empty());
        return *values.rbegin();
    }

    T front() { // returns the minimum element in the deque
        assert(!empty());
        return *values.begin();
    }

    T pop_back() { // returns and removes the maximum element in the deque
        assert(!empty());
        T to_return = back();
        values.erase(--values.end());
        return to_return;
    }

    T pop_front() { // returns and removes the minimum element in the deque
        assert(!empty());
        T to_return = front();
        values.erase(values.begin());
        return to_return;
    }

    bool empty() {return values.empty();}
    int size() const {return (int) values.size();}
    void clear() {values.clear();}

    priority_deque<T>& operator=(priority_deque<T>&& other) noexcept {
        swap(values, other.values); return *this;
    }

    void swap(priority_deque<T>&& other) noexcept {
        swap(values, other.values);
    }
    bool operator == (const priority_deque<T> &other) const { return values==other.values;}
    bool operator != (const priority_deque<T> &other) const { return !(*this == other);}
};