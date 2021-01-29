// query_range_segment_tree_lazy_index_sum_min_max
// or
// query_range_segment_tree_lazy_sum_min_max

// Finds the element less than target furthest to the right. If no such p exists, returns -1
template<typename T>
int find_less_than(SegmentTree<T> &st, int left, int right, T target) {
    return st.find_last(left, right, [&](const typename SegmentTree<T>::Node &node) {
        if (node.mn < target)
            return true;
        return false;
    });
}