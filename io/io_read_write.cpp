template<typename T> // supported for vector, list, forward_list and deque
void read(T &&ref, int n, int start=0) {
    assert(0<=start && 0<=n); ref.resize(start+n);
    for(auto it=next(begin(ref), start); it != end(ref); it++)
        cin >> *it;
}

template<typename T> // supported for vector, list and deque
void write(T &&ref, int n=-1, int start=0, string mid=" ", string end_l="\n") {
    if(n < 0) n = (int) ref.size();
    assert(0<=start && 0<=n && start+n<=(int)ref.size());
    auto end_it = next(begin(ref), start+n);
    for(auto it=next(begin(ref), start); it != end_it; it++)
        cout << *it << mid; cout << end_l;
}