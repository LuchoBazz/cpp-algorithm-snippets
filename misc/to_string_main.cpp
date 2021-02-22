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

#ifndef ONLINE_JUDGE
#define writer_out cerr
#define debug(x) writer_out<<"["<<#x": "<<to_string(x)<<"] ";
#define debugln(x) debug(x); writer_out<<"\n";
#else
#define debug(x)
#define debugln(x)
#endif