# sorting-benchmark

Benchmarking sorting algorithms across multiple input distributions in C++. Each algorithm is timed on 8 different input types, with results written to CSV files for analysis.

## Algorithms

| Algorithm | Variants |
|---|---|
| Heap Sort | — |
| Merge Sort | — |
| Quick Sort | Random pivot, Last element pivot, Median-of-three |
| Radix Sort | Base 10, Base 2¹⁶ (65536) |
| Shell Sort | Classic, Knuth generalized (k=3), Knuth generalized (k=5) |
| Count Sort | — |

## Input Distributions

| Distribution | Description |
|---|---|
| Sorted ascending | Already in order |
| Sorted descending | Reverse order |
| Nearly sorted ascending | Sorted with a few random swaps |
| Nearly sorted descending | Reverse sorted with a few random swaps |
| Uniform random | Values drawn uniformly from [min, max] |
| Nearly identical | Values clustered tightly around a random center |
| Gaussian | Values concentrated around a random mean |
| Inverted Gaussian | Values concentrated at both extremes |

Each test iteration uses randomly generated `min`/`max` bounds, alternating between small integer ranges (±100000) and full `long long` ranges, at sizes of 1000 and 1,000,000 elements.

## Project Structure

```
.
├── main.cpp          # Benchmark runner
├── generator.h       # Templated input generators
└── sortari/
    ├── heap_sort.h
    ├── merge_sort.h
    ├── quick_sort_random.h
    ├── quick_sort_last_element.h
    ├── quick_sort_m3.h
    ├── radix_sort.h
    ├── shell_sort.h
    └── count_sort.h
```

## Output

One CSV file per algorithm:

```
output_heap_sort.csv
output_merge_sort.csv
output_quick_sort_random.csv
output_quick_sort_le.csv
output_quick_sort_m3.csv
output_radix_sort_10.csv
output_radix_sort_2^16.csv
output_shell_sort.csv
output_shell_sort_knuth3.csv
output_shell_sort_knuth5.csv
output_count_sort.csv
```

Each row has the format:

```
N, min, max, <time>, <valid>, <time>, <valid>, ...
```

Timing is in seconds. A value of `-1` means the sort threw an exception for that input. The `valid` column is 1 if the output is correctly sorted, 0 otherwise.

## Build & Run

**Requirements:** C++17 or later.

```bash
g++ -std=c++17 -O2 -o benchmark main.cpp
./benchmark
```

Enter the number of test iterations when prompted.

## Authors
Stoica Antonia — quick sort, radix sort, main benchmark runner
Filote Ionuț — input generators, heap sort, merge sort
Pîrvulescu Gabriela — count sort, shell sort
