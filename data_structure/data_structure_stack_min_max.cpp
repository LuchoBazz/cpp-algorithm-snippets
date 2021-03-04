template<typename T>
struct Wrapper {
    T value;
    T op;
};

template<typename T, typename Operate>
class Stack {
public:
    stack<Wrapper<T>> st;
    T global_op;
    Operate Oper;
    
    Stack() {}
    
    void push(T value) {
        if(st.empty()) {
            global_op = value;
        } else {
            global_op = Oper(global_op, value);
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
    
    T top() {
        assert(!st.empty());
        return st.top().value;
    }

    T operate() {
        assert(!st.empty());
        return st.top().op;
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