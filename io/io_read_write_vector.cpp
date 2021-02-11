template<typename T>
void read(vector<T> &ref, int n, int start=0) {
    ref.resize(start+n);
    for(int i = start; i < start + n; ++i) cin >> ref[i];
}

template<typename T>
void write(const vector<T> &ref, int n=-1, int start=0, string mid=" ", string end="\n") {
    if(n < 0) n = (int) ref.size();
    for(int i = start; i < start + n; ++i) 
        cout << ref[i] << mid; cout << end;
}