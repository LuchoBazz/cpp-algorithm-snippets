// query_range_segment_tree_lazy_index_sum_min_max
// or
// query_range_segment_tree_lazy_sum_min_max

// Returns min(p | p <=right && sum[left..p]>=sum). If no such p exists, returns -1
template<typename T>
int sum_lower_bound(SegmentTree<T> &st, int left, int right, T sum) {
    T accum_sum = T(0);
    return st.find_first(left, right, [&](const typename SegmentTree<T>::Node &node) {
        if (accum_sum + node.sum >= sum)
            return true;
        accum_sum += node.sum;
        return false;
    });
}