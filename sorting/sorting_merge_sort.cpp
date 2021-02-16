void merge(vector<int> &v, int left, int mid, int right) {
    vector<int> ordered(right-left+1);
    int i = left, j = mid + 1, idx = 0;
    while(i <= mid ||  j <= right) {
        if(i <= mid && j <= right) {
            if(v[i] < v[j]) {
                ordered[idx++] = v[i++];    
            } else if(v[i] > v[j]) {
                ordered[idx++] = v[j++];
            } else {
                ordered[idx++] = v[i++];
                ordered[idx++] = v[j++];
            }
        } else if(i <= mid) {
            ordered[idx++] = v[i++];
        } else if(j <= right) {
            ordered[idx++] = v[j++];
        }
    }
    for(idx=0, i = left; i <= right; i++)
        v[i] = ordered[idx++];
}

void merge_sort(vector<int> &v, int left, int right) {
    if(left == right) {
        return;
    } else if(left < right) {
        int mid = (left+right)/2;
        merge_sort(v, left, mid);
        merge_sort(v, mid+1, right);
        merge(v, left, mid, right);    
    }
}

void merge_sort(vector<int> &v) {
    merge_sort(v, 0, (int) v.size() - 1);
}
// Usage:
// Vector<int> A { ... };
// merge_sort(A);