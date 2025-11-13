---
sidebar_position: 4
title: Working with 128-bit Integers in C++
sidebar_label: Working with 128-bit Integers
---

## What this code does (short)

The code defines a 128-bit integer type for GNU C++ (`__int128`) and provides two stream operators so you can use `cin >>` and `cout <<` with that type. This is useful because the standard iostream library does not know how to read or print `__int128`.

---

## Line-by-line explanation

```cpp
// for: GNU C++20 (64)
using i128 = __int128;
const i128 ONE_128 = i128(1);
const i128 ZERO_128 = i128(0);
```

* `using i128 = __int128;` creates an alias `i128` for the builtin GNU type `__int128`.
* `__int128` is a 128-bit signed integer available in GNU compilers on 64-bit systems. It stores much bigger values than `long long`.

* These two lines define constants `ONE_128` and `ZERO_128` with values `1` and `0` typed as `i128`.
* They make the code clearer when you need literal 128-bit constants.

---

### Input operator: `operator >>`

```cpp
std::istream &operator>>(std::istream &is, i128 &n) {
    n = 0;
    std::string s; is >> s;
    for (auto c : s) {
        n = 10 * n + c - '0';
    }
    return is;
}
```

* This overload lets you write `cin >> my_i128_variable;`.

* Steps it performs:

  1. Set `n` to zero.
  2. Read the whole token from the stream into a `std::string s`. This skips leading whitespace and reads until the next whitespace.
  3. For each character `c` in the string, it updates `n = 10*n + (c - '0')`. That converts the decimal digits to a numeric value.
  4. Return the input stream reference so chaining (e.g., `cin >> a >> b;`) works.

* **Important limitations**:

  * The code assumes the string contains only digits (`'0'`–`'9'`). It does **not** handle a leading `-` sign, a leading `+`, or invalid characters.
  * It does not check for overflow. If the number in the input is larger than 128 bits can hold, the behavior is undefined (it will wrap or give wrong results).

---

### Output operator: `operator <<`

```cpp
std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
```

* This overload lets you write `cout << my_i128_variable;`.

* Steps it performs:

  1. If `n` is zero, it prints `0` and returns.
  2. Otherwise it builds a string `s` with the digits of `n` in reverse order: take `n % 10` to get the last digit, append the corresponding character, and then divide `n` by 10.
  3. Reverse the string to get the correct digit order.
  4. Output the string and return the stream.

**⚠️ Warning:**
*The provided code only works correctly for **positive integers**. It does **not** support negative numbers or the sign `-`, and printing a negative `i128` will also produce incorrect output.*

* **Important limitations**:

  * The code assumes `n` is non-negative. If `n` is negative, the `while (n > 0)` loop never runs and the result is wrong. Typical fix: check `if (n < 0) { os << '-'; n = -n; }` before converting digits.
  * Converting a 128-bit integer to decimal takes time proportional to the number of digits (about 39 digits max for 128-bit), which is fine for competitive programming.

---

## How to use

```cpp
i128 a;
cin >> a;
cout << a << '\n';
```
