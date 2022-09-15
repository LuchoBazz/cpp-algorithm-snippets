#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename T>
string to_string(queue<T> q) {
    bool first = true;
    string res = "{";
    while(!q.empty()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;
}

template <typename T>
string to_string(stack<T> st) {
    bool first = true;
    string res = "{";
    while(!st.empty()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(st.top());
        st.pop();
    }
    res += "}";
    return res;
}

template<typename T, typename Sequence=vector<T>, typename Compare=less<T>>
string to_string(priority_queue<T, Sequence, Compare> pq) {
    bool first = true;
    string res = "{";
    while(!pq.empty()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
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
    for (auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(const pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(const tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <size_t N>
string to_string(const bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

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

// #ifdef DEBUG
// #include "debug.h"
// #else
// #define debug(...) 42
// #endif