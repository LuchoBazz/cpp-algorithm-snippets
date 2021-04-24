namespace data_structure {

template<typename T>
T get_min(multiset<T> &st) {
    assert(!st.empty()); return *st.begin();
}
template<typename T> T get_max(multiset<T> &st) {
    assert(!st.empty()); return *st.rbegin();
}
template<typename T>
T erase_min(multiset<T> &st) {
    assert(!st.empty()); T to_return = get_min(st);
    st.erase(st.begin()); return to_return;
}
template<typename T> T erase_max(multiset<T> &st) {
    assert(!st.empty()); T to_return = get_max(st);
    st.erase(--st.end()); return to_return;
}


/**
 * Description: calculates the median of a data set, supporting add and erase operations
 * Time:
 *      add: O(log2(n))
 *      erase: O(log2(n))
 *      get_median: O(log2(n))
 * Verification: t.ly/P4wn
 */

template<typename T>
struct Median {
    int n;
    multiset<T> left;
    multiset<T> right;

    Median() : n(0) {}

    bool add(const T &value) {
        int left_size = (int) left.size();
        int right_size = (int) right.size();
        n++;
        if(left_size==0 && right_size==0) {
            right.insert(value);
            return true;
        } else if(left_size == 0 && right_size==1) {
            T right_current = get_min(right);
            if(value > right_current) {
                erase_min(right);
                right.insert(value);
                left.insert(right_current);
            } else if(value <= right_current) {
                left.insert(value);
            }
            return true;
        } else if(left_size == right_size) {
            T left_current = get_max(left);
            if(value >= left_current) {
                right.insert(value);
            } else if(value < left_current) {
                erase_max(left);
                left.insert(value);
                right.insert(left_current);
            }
            return true;
        } else if(left_size+1 == right_size) {
            T left_current = get_max(left);
            T right_current = get_min(right);
            if(value <= left_current) {
                left.insert(value);
            } else if(value > left_current && value > right_current) {
                erase_min(right);
                left.insert(right_current);
                right.insert(value);
            } else if(value > left_current && value <= right_current) {
                left.insert(value);
            }
            return true;
        }
        n--;
        return false;
    }

    bool erase(const int &value) {
        int left_size = (int) left.size();
        int right_size = (int) right.size();
        n--;
        if(left_size>0 && right_size>0) {
            T left_current = get_max(left);
            T right_current = get_min(right);
            if(value <= left_current) {
                auto it = left.find(value);
                if(it != left.end()) {
                    left.erase(it);
                    left_size = (int) left.size();
                    if(abs(right_size - left_size) > 1) {
                        erase_min(right);
                        left.insert(right_current);
                    }
                    return true;
                }
            } else if(value > left_current && value > right_current) {
                auto it = right.find(value);
                if(it != left.end()) {
                    right.erase(it);
                    right_size = (int) right.size();
                    if(left_size - right_size > 0) {
                        erase_max(left);
                        right.insert(left_current);
                    }
                    return true;
                }
            } else if(value > left_current && value <= right_current) {
                auto it = right.find(value);
                if(it != left.end()) {
                    right.erase(it);
                    right_size = (int) right.size();
                    if(left_size - right_size > 0) {
                        erase_max(left);
                        right.insert(left_current);
                    }
                    return true;
                }
            }
        } else if(left_size==0 && right_size>0) {
            auto it = right.find(value);
            if(it != left.end()) {
                right.erase(it);
                return true;
            }
        }
        n++;
        return false;
    }

    int get_median() {
        int answer;
        if(n & 1) { // k is odd
            answer = get_min(right); // answer for k odd: min(right)
        } else { // k is even
            answer = min(get_max(left), get_min(right)); // answer for k even: min(max(left), min(right))
        }
        return answer;
    }

    int size() { return n; }
    bool empty() {return n==0;}
};

}
using data_structure::Median;