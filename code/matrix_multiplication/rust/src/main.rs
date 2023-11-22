use rayon::prelude::*;
use std::time::Instant;

// Function to perform matrix multiplication in serial
fn matrix_multiply_serial(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>, c: &mut Vec<Vec<i32>>) {
    for i in 0..a.len() {
        for j in 0..b[0].len() {
            c[i][j] = 0;
            for k in 0..a[0].len() {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to perform matrix multiplication in parallel using Rayon
fn matrix_multiply_parallel(
    a: &Vec<Vec<i32>>,
    b: &Vec<Vec<i32>>,
    c: &mut Vec<Vec<i32>>,
    num_threads: usize,
) {
    rayon::ThreadPoolBuilder::new()
        .num_threads(num_threads)
        .build_global()
        .unwrap();

    c.par_iter_mut().enumerate().for_each(|(i, row)| {
        for j in 0..b[0].len() {
            row[j] = a[i]
                .iter()
                .zip(b.iter().map(|col| col[j]))
                .map(|(&x, y)| x * y)
                .sum();
        }
    });
}

fn main() {
    // Editable parameters
    let matrix_size = 64;
    let num_threads = 1;

    // Initialize matrices A, B, and C
    let a: Vec<Vec<i32>> = vec![vec![2; matrix_size]; matrix_size];
    let b: Vec<Vec<i32>> = vec![vec![3; matrix_size]; matrix_size];
    let mut c: Vec<Vec<i32>> = vec![vec![0; matrix_size]; matrix_size];

    // Serial execution
    let serial_start_time = Instant::now();
    matrix_multiply_serial(&a, &b, &mut c);
    let serial_end_time = Instant::now();
    let serial_execution_time = serial_end_time
        .duration_since(serial_start_time)
        .as_secs_f64();

    // Reset matrix C
    c = vec![vec![0; matrix_size]; matrix_size];

    // Parallel execution using Rayon
    let parallel_start_time = Instant::now();
    matrix_multiply_parallel(&a, &b, &mut c, num_threads);
    let parallel_end_time = Instant::now();
    let parallel_execution_time = parallel_end_time
        .duration_since(parallel_start_time)
        .as_secs_f64();

    // Print the time taken in serial and parallel execution
    println!("Serial execution time: {} seconds.", serial_execution_time);
    println!(
        "Parallel execution time: {} seconds.",
        parallel_execution_time
    );

    // Calculate and print speedup
    let speedup = serial_execution_time / parallel_execution_time;
    println!("Speedup: {}", speedup);
}
