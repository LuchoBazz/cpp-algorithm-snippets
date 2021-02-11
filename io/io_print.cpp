void print() {cout << "\n";}
template<class H, class... T> void print(const H& h, const T&... t) {
    cout << h;
    if(sizeof...(t)) cout << ' '; print(t...);
}