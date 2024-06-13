template <typename T, typename Sequence = vector<T>, typename Compare = less<T>>
using template_heap = priority_queue<T, Sequence, Compare>;

template <typename T> using max_heap = template_heap<T>;

template <typename T> using min_heap = template_heap<T, vector<T>, greater<T>>;

#define pop_heap(heap)                                                         \
    heap.top();                                                                \
    heap.pop();
