template<typename T>
struct Wrapper {
    T value;
    T op;
};

template<typename T, typename Compare>
class Stack {
public:
    stack<Wrapper<T>> st;
    T global_op;
    Compare comp;
    
    Stack() {}
    
    void push(T value) {
        if(st.empty()) {
            global_op = value;
        } else {
            global_op = comp(global_op, value);
        }
        st.push(Wrapper<T>{value, global_op});
    }
    
    void pop() {
        assert(!st.empty());
        st.pop();
        if(!st.empty()) {
            global_op = st.top().op;
        } else {
            global_op = T{};
        }
    }
    
    Wrapper<T> top() {
        assert(!st.empty());
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};

struct Min {
    template <typename T> T operator()(T x, T y) { return min<T>(x, y); } };
struct Max {
    template <typename T> T operator()(T x, T y) { return max<T>(x, y); } };

template<typename T> using MinStack = Stack<T, Min>;
template<typename T> using MaxStack = Stack<T, Max>;