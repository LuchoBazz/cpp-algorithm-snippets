// ref codeforces: https://codeforces.com/blog/entry/10355
// ref geeksforgeeks: https://www.geeksforgeeks.org/stl-ropes-in-c/

#include <ext/rope>
using namespace __gnu_cxx;

#define trav_rope(it, v) for(auto it=v.mutable_begin(); it!= v.mutable_end(); ++it)
#define all_rope(rp) (rp).mutable_begin(), (rp).mutable_end()

// trav_rope(it, v) cout << *it << " ";

// Use `crope` for strings

// push_back(T val): 
//      This function is used to input a character at the end of the rope
//      Time Complexity: O(log2(n))
// pop_back():
//      this function is used to delete the last character from the rope
//      Time Complexity: O(log2(n))
// insert(int i, rope r): !!!!!!!!!!!!!!!!WARING!!!!!!!!!!! Worst Case: O(N).
//      Inserts the contents of `r` before the i-th element.
//      Time Complexity: Best Case: O(log N) and Worst Case: O(N). 
// erase(int i, int n):
//      Erases n elements, starting with the i-th element
//      Time Complexity: O(log2(n))
// substr(int i, int n):
//      Returns a new rope whose elements are the n elements starting at the position i-th
//      Time Complexity: O(log2(n))
// replace(int i, int n, rope r):
//      Replaces the n elements beginning with the i-th element with the elements in r
//      Time Complexity: O(log2(n))
// concatenate(+):
//      Concatenate two ropes using the ‘+’ symbol
//      Time Complexity: O(1)
