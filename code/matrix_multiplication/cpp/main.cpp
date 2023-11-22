#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

// Function to perform matrix multiplication
void matrixMultiplication(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int numRows = A.size();
    int numCols = B[0].size();
    int innerDim = B.size();

    #pragma omp parallel for
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < innerDim; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int numRows = 1000;
    int numCols = 1000;
    int innerDim = 1000;

    // Initialize matrices A, B, and C
    std::vector<std::vector<int>> A(numRows, std::vector<int>(innerDim, 1));
    std::vector<std::vector<int>> B(innerDim, std::vector<int>(numCols, 2));
    std::vector<std::vector<int>> C(numRows, std::vector<int>(numCols, 0));

    // Measure the execution time of the serial version
    auto start_serial = std::chrono::high_resolution_clock::now();
    matrixMultiplication(A, B, C);
    auto end_serial = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> serial_duration = end_serial - start_serial;

    // Reset matrix C for the parallel version
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            C[i][j] = 0;
        }
    }

    // Measure the execution time of the parallel version
    auto start_parallel = std::chrono::high_resolution_clock::now();
    matrixMultiplication(A, B, C);
    auto end_parallel = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallel_duration = end_parallel - start_parallel;

    std::cout << "Serial execution time: " << serial_duration.count() << " seconds" << std::endl;
    std::cout << "Parallel execution time: " << parallel_duration.count() << " seconds" << std::endl;

    return 0;
}
