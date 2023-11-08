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
