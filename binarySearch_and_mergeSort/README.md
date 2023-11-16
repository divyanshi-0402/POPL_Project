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


## Performance testing set up

Each problem has following files: `main_rust`, `main_cpp`, `gen`. First two are
about compiling the programs. Every program recieves its input on `stdin` 
and write results in `stdout`. `gen` will prepare test data:
three input sets `inp_low`, `inp_mid`, `inp_hi` with increasing problem sizes.
Generally, `inp_low` contains smallest inputs, and `inp_hi` contains millions
of entities and it usually takes few seconds to solve the problem of a such size.
 `common/compare_performace.sh` which will perform N (N =
10) runs of every input on evety program and everage the result.
