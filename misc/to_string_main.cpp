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

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

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

// add template here

#define writer_out cerr
void debug_out() { writer_out << "\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  writer_out << to_string(H);
  if(sizeof...(T)) writer_out << "] ["; else writer_out << "]";
  debug_out(T...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) writer_out << "[" << #__VA_ARGS__ << "]: [" , debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif