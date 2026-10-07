# C++ Pointers and Dynamic Memory

A small C++ learning repository covering the fundamentals of **pointers, references, arrays, multidimensional arrays, functions, and dynamic memory allocation**.

The examples are written to help students understand how pointers work at a practical level and how memory is accessed and manipulated in C++.

## Topics Covered

* Basic pointers
* Address-of operator (`&`)
* Dereference operator (`*`)
* Pointer to pointer (`**`)
* Pass by value
* Passing addresses to functions
* Pointers and arrays
* Arrays as function arguments
* Character arrays and pointers
* Null terminator (`'\0'`)
* Pointers with 2D arrays
* 2D arrays as function arguments
* Dynamic memory allocation
* `new` and `delete`
* Dynamic arrays
* Dynamic 2D arrays
* Dynamic character arrays
* Returning pointers from functions
* Pointer arithmetic

## Examples

The code demonstrates concepts such as:

```cpp
int a = 5;
int* ptr = &a;

cout << *ptr;
```

It also demonstrates the relationship between array indexing and pointer arithmetic:

```cpp
arr[i] == *(arr + i)
```

For multidimensional arrays:

```cpp
arr[i][j] == *(*(arr + i) + j)
```

## Dynamic Memory

The repository includes examples of allocating and releasing memory dynamically:

```cpp
int* ptr = new int;
delete ptr;
```

and dynamic arrays:

```cpp
int* arr = new int[5];
delete[] arr;
```

It also demonstrates dynamically allocated 2D integer and character arrays.

## Purpose

The goal of this repository is to provide simple examples that students can run, modify, and experiment with while learning C++ pointers and memory management.

The code intentionally focuses on the fundamental concepts rather than using advanced C++ features.

## Requirements

* A C++ compiler such as:

  * GCC / G++
  * MinGW
  * Visual Studio
  * Clang
* Basic knowledge of C++ syntax
* A code editor or IDE

## Running the Code

Compile the program using a C++ compiler:

```bash
g++ main.cpp -o main
```

Then run it:

### Windows

```bash
main.exe
```

### Linux / macOS

```bash
./main
```

## Repository Structure

```text
cpp-pointers-and-dynamic-memory/
│
├── main.cpp
└── README.md
```

## Important Note

Some examples are intentionally designed to demonstrate what happens when pointers and memory are used incorrectly. When experimenting with the code, pay particular attention to:

* Dereferencing pointers
* Memory allocation and deallocation
* `delete` vs `delete[]`
* Null-terminated character arrays
* Pointer lifetime
* Returning addresses from functions

The purpose is to understand how these concepts work and what can go wrong when they are misused.
