#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <omp.h>

using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort algorithm
void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

#pragma omp task
        quicksort(arr, low, pi - 1);

#pragma omp task
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    // Set the number of threads and data size
    int num_threads = 2;    // Adjust as needed
    int data_size = 100000; // Adjust as needed

    // Initialize the array with random values
    vector<int> arr(data_size);
    srand(time(0));
    for (int i = 0; i < data_size; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Serial execution
    double start_serial = omp_get_wtime();
    quicksort(arr, 0, data_size - 1);
    double end_serial = omp_get_wtime();
    cout << "Serial execution time: " << end_serial - start_serial << " seconds" << endl;

    // Reset the array for parallel execution
    for (int i = 0; i < data_size; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Parallel execution
    omp_set_num_threads(num_threads);
    double start_parallel = omp_get_wtime();
#pragma omp parallel
#pragma omp single
    quicksort(arr, 0, data_size - 1);
    double end_parallel = omp_get_wtime();
    cout << "Parallel execution time: " << end_parallel - start_parallel << " seconds" << endl;

    // Calculate speedup
    double speedup = (end_serial - start_serial) / (end_parallel - start_parallel);
    cout << "Speedup: " << speedup << endl;

    return 0;
}
