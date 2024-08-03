# Parallel bubble sorting

## Abstract

Sort lists of integers, with bubble sorting and MPI (Message Passing Interface)!

There are 2 versions: A and B.

Version A: Odd/even sorting of an array of [p] elements on [p] processes.
Features:
- Create a vector of the desired size
- Fill with random values (between 0 and 99)
- Display initial vector, sorted vector and calculation time
- Number of processes must be even

VersionB: Odd/even sorting of an array of [n] elements [p] processes, where [n]=m*[p]
- Number of processes must be even
- The number of elements must be divisible by the number of processes

## How to

```bash
# compile
04_parallel_bubble_sorting % cmake -S . -B build
04_parallel_bubble_sorting % cmake --build build

# execute
04_parallel_bubble_sorting % mpiexec -n [p] ./build/exec_code version_A
04_parallel_bubble_sorting % mpiexec -n [p] ./build/exec_code version_B [n]

# tests
04_parallel_bubble_sorting % ctest

# examples
04_parallel_bubble_sorting % mpiexec -n 4 ./build/exec_code version_A
04_parallel_bubble_sorting % mpiexec -n 4 ./build/exec_code version_B 36
```
