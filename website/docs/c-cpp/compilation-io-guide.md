---
sidebar_position: 1
title: Compilation IO Guide
sidebar_label: Compilation IO Guide
---

## Compile and Execute C++ Program with Input and Output Redirection

**Standard**
```bash
g++-14 -std=c++17 -Wall -O2 -fno-sanitize-recover -o A A.cpp
```

**Debug**
```bash
g++-14 -std=c++17 -DDEBUG -Wall -O2 -fno-sanitize-recover -o A A.cpp
```

**Running**
```bash
./A < A.in > A.out
```

### Explanation
This command compiles and executes a C++ program, redirecting the input and output to specific files. Below is a breakdown of the command: _(Useful for competitive programming)_

- `g++-14`: Specifies the version of the GNU C++ Compiler, in this case, version 14.
- `-std=c++17`: Instructs the compiler to use the C++17 standard for compilation.
- `-Wall`: Enables all compiler warnings, which helps in identifying potential issues.
- `-O2`: Activates a moderate level of optimization to improve the performance of the compiled program.
- `-fno-sanitize-recover`: Ensures the program stops execution immediately when encountering a sanitization error, instead of attempting to recover.
- `-DDEBUG`: Defines the macro `DEBUG`, enabling any conditional compilation sections related to debugging within the source code.
- `-o A`: Specifies that the output executable file will be named `A`.
- `A.cpp`: The source file to be compiled.
- `./A < A.in > A.out`: Executes the compiled program, reading input from the file `A.in` and writing the output to the file `A.out`.

This method is efficient for running programs with predefined input and capturing the output into a file for further analysis or documentation purposes.
