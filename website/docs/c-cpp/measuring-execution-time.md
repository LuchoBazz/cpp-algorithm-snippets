---
sidebar_position: 3
title: Measuring Execution Time in C++
sidebar_label: Measuring Execution Time in C++
---

## Measuring Execution Time in C++

This simple example shows how to measure the execution time of a block of code using the `<chrono>` library.

### Code Example

```cpp
// #include <chrono>

auto start = chrono::high_resolution_clock::now();

// CODE TO BE MEASURED
// Example: for (int i = 0; i < 1000000; ++i) {}

auto end = chrono::high_resolution_clock::now();

chrono::duration<double, milli> duration = end - start;
cout << "Execution time: " << duration.count() << " ms" << endl;
```

### Explanation

* `chrono::high_resolution_clock::now()`
  Captures the current high-precision timestamp (start and end).

* `end - start`
  Calculates the elapsed time between the two timestamps.

* `chrono::duration<double, milli>`
  Converts the time difference into **milliseconds**.

* `duration.count()`
  Returns the numerical value of the elapsed time, which is printed to the console.

### Tip

You can replace the comment `// CODE TO BE MEASURED` with any operation you want to benchmark — for example, loops, function calls, or algorithm executions.
