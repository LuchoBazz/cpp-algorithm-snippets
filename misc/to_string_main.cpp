template <typename A, typename B>
string to_string(const pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(const tuple<A, B, C, D> p);

template <size_t N>
string to_string(const bitset<N> v);

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

// add template here

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template<class T>
void println(const T &data) {
#ifndef ONLINE_JUDGE
    cout << to_string((T)data) << endl;
#endif
}

#define writer_out cout
void debug_out() { writer_out << "\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  writer_out << to_string(H);
  if(sizeof...(T)) writer_out << "] ["; else writer_out << "]";
  debug_out(T...);
}
 
#ifndef LOCAL
#define debug(...) writer_out << "[" << #__VA_ARGS__ << "]: [" , debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif