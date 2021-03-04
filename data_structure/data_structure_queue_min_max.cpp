template<typename T>
struct Wrapper {
    T value;
    T op;
};


template <typename T, typename Operate>
struct Queue {
    stack<Wrapper<T>> s1;
    stack<Wrapper<T>> s2;
    
    Operate Oper;

    T operate() {
        if(s1.empty() || s2.empty()) {
            return s1.empty()?s2.top().op : s1.top().op;
        } else {
            return Oper(s1.top().op, s2.top().op);
        }
    }

    void add_last(T value) {
        T value_op;
        if(s1.empty()) {
            value_op = value;
        } else {
            value_op = Oper(value, s1.top().op);
        }
        s1.push(Wrapper<T>{value, value_op});
    }

    T remove_first() {
        if (s2.empty()) {
            while (!s1.empty()) {
                T value = s1.top().value;
                s1.pop();
                T value_op = s2.empty() ? value : Oper(value, s2.top().op);
                s2.push(Wrapper<T>{value, value_op});
            }
        }
        T value = s2.top().value;
        s2.pop();
        return value;
    }
};

struct Min {
    template <typename T> T operator()(T x, T y) { return min<T>(x, y); } };
struct Max {
    template <typename T> T operator()(T x, T y) { return max<T>(x, y); } };

template<typename T> using MinQueue = Queue<T, Min>;
template<typename T> using MaxQueue = Queue<T, Max>;
