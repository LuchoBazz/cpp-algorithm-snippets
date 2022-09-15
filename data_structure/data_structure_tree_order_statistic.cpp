#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
using __gnu_pbds::tree;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree_order_statistics_node_update;
using __gnu_pbds::null_type;

// _GLIBCXX_DEBUG must not be defined otherwise some internal check will fail
#undef _GLIBCXX_DEBUG

template <typename K, typename V, typename Comp = less<K>>
using indexed_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = less<K>>
using indexed_set = indexed_map<K, null_type, Comp>;

// ¡¡IMPORTANT!! (for using less_equals<K>)
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
// don't use .find() because it will always return .end()
template <typename K, typename V, typename Comp = less_equal<K>>
using indexed_multimap = indexed_map<K, V, Comp>;

template <typename K, typename Comp = less_equal<K>>
using indexed_multiset = indexed_map<K, null_type, Comp>;

// Reference: https://codeforces.com/blog/entry/11080

// Usage
// 1) Return the value of the idx index
//    auto it = any.find_by_order(idx); (0-indexed)
//    (*it).first, (*it).second
//    {1, 2, 2, 2, 3, 4, 7}
//    any.find_by_order(0); -> *it return value 1
//    any.find_by_order(1); -> *it return value 2
//    any.find_by_order(3); -> *it return value 2
//    any.find_by_order(6); -> *it return value 7
//    any.find_by_order(-1);  -> it == any.end()
//    any.find_by_order(100); -> it == any.end()

// 2) Get the index of the key value
//    int index = any.order_of_key(key); (0-indexed)
//    {1, 2, 2, 2, 3, 4, 7}
//    any.order_of_key(2)   -> return index 1
//    any.order_of_key(5)   -> return index 6

// 3) Correct way to use erase:
//    any.erase(any.find_by_order(any.order_of_key(val)));
