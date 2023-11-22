# POPL_Project
Compare the performance and implementation complexity of multithreaded applications in Rust and C++.

## Table of contents:
* Summary 
* Motivation
* Benchmarks
* Results

## Summary
At this point, we have executed and performed preliminary analysis on the multithreading performance on three benchmarks: matrix multiplication, and searching algorithms (binary search),and sorting algorithms (merge sort) utilizing multithreading libraries and Rayon, which is implemented specifically for Rust to that of OpenMP implementation for C++.​

We have varied the number of threads for each algorithm, as well as the data size and calculated the time of execution while varying these parameters for the benchmark we have started with.

## Motivation
As developers, it is our responsibility to create concurrent, quick, and accurate apps that grow with the hardware. When breaking down an algorithm into multiple parallel tasks, developers must exercise caution with unexpected types of errors like as deadlock and data-races. Hence, we need to recognise these faults and foresee them in order to achieve better performance through parallelism. Due to its perceived ability to offer thread-safety at no cost, Rust is quickly gaining popularity among developers and industries. Rust provides message-based channels for communication and data locks for secure concurrency.

## Benchmarks
Given the same setup for both rust and c++, ubuntu version (write setup description here),we are going to compare the serial performance of the given benchmarks (without rayon and openMP),then after identifying the part of the code we are going to parallelise we are going to compare the parallel performance of the given benchmarks (with rayon and openMP), and finally we will compare serial vs parallel performance for the given benchmarks.
The bench marks are as follows:
  * Matrix multiplication
  * Searching algorithms (binary search)
  * Sorting algorithms (merge sort)

## Results:
1. Serial rust (without rayon) vs serial c++ (without openMP)
2. Parallel rust (with rayon) vs serial c++ (with openMP)
3. Serial Rust (without rayon) vs Parallel Rust (with rayon)
4. Serial C++ (without OpenMP) vs Parallel C++ (with OpenMP)


\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

# Binary search

## Problem description

For the given arrays `A` and `B` print index `j` that is `A[j] = B[i]` for
every `i`, or `-1` if `B[i]` is not found in the `A`.  The first line contains
`n`, which is number of elements in `A`. And `n` integer numbers, which is
`A`'s elements. Elements of `A` in ascending order. The second line containes
the same information for `B` array.

```
Sample Input:
5 1 5 8 12 13
5 8 1 23 1 11

Sample Output:
3 1 -1 1 -1
```

# Mergesort

## Problem description

For the given arrays `A` calculate number of swaps needed to sort the array.
More formal, calculate number of pairs `i, j` where  `i < j` and `A[i] > A[j]`. 
The first line contains number of elements in `A`. The second line contains the elements.
```
Sample Input:
5
2 3 9 2 9

Sample Output:
2
```


### Performance testing set up (For Binary Search and Merge Sort)

Each problem has following files: `main_rust`, `main_cpp`, `gen`. First two are
about compiling the programs. Every program recieves its input on `stdin` 
and write results in `stdout`. `gen` will prepare test data:
three input sets `inp_low`, `inp_mid`, `inp_hi` with increasing problem sizes.
Generally, `inp_low` contains smallest inputs, and `inp_hi` contains millions
of entities and it usually takes few seconds to solve the problem of a such size.

cd to the generator directory. Following command lines are used to generate test data
for `inp_low`, `inp_mid`, `inp_hi` respectively.

```
echo 10000    | cargo run > ../inp_low;
echo 1000000  | cargo run > ../inp_mid;
echo 10000000 | cargo run > ../inp_hi;
```
```cd ..``` back to the main directory (binary_search / mergesort).

The next command line is used to compile C++ program:

```
	g++ -std=c++11 -O2 -DNDEBUG -o main_cpp main.cpp
```

The next command line is used to compile Rust program:

```
	rustc -O --crate-name main_rust main.rs
```

Run `common/compare_performace.sh` which will perform N (N =
10) runs of every input on evety program and average the result.

```
../common/compare_performance.sh
```

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

# Matrix Multiplication

## Problem description

Binary operation that produces a matrix from two matrices. 
It is a compute-bound problem,so we can observe how the parallelism libraries behave on it. Additionally, we may see the behavior of these algorithms when built in a cache-friendly or multi-thread-advantageous manner. Another comparison that can be made is between the two approaches of handling a task division given the real job division (row first dot products).


### Performance testing set up (For Matrix Multiplication)
C++ and Rust directories have ```main.rs``` and ```main.cpp``` for respective algorithms.

The next command line is used to compile Rust program:
If you are compiling for the first time (else skip to the next command) :

```
	cargo build
```

```
	cargo run
```
