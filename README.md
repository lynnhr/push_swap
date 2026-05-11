*This project has been created as part of the 42 curriculum by atchelde & lhaydar*

## Description

A random list of integers is given via command line arguments.
We start with two empty stacks A and B.
At the end, stack B must be empty and all integers must be in stack A, sorted in ascending order, using the minimal number of operations.

---

## Compilation

```bash
make        # build push_swap
make re     # clean rebuild
make fclean # remove binary and objects
```

---

## Usage

```bash
./push_swap [FLAGS] <integers>
```

Integers can be passed as separate arguments or as a single quoted string:

```bash
./push_swap 5 3 1 4 2
./push_swap "5 3 1 4 2"
```

The sorted operation sequence is printed to stdout, one operation per line.
Errors (invalid input, duplicates, overflow) are printed to stderr.

---

## Flags

| Flag         | Algorithm      | Complexity   | Best for        |
|--------------|----------------|--------------|-----------------|
| `--adaptive` | auto-select    | varies       | default         |
| `--simple`   | selection sort | O(n²)        | small / sorted  |
| `--medium`   | chunk sort     | O(n√n)       | medium inputs   |
| `--complex`  | radix sort     | O(n log n)   | large inputs    |
| `--bench`    | (stats mode)   | —            | profiling       |

Flags must come before the integers. `--adaptive` is the default when no flag is given.

---

## Algorithms

### Selection Sort (`--simple`)

Repeatedly finds the minimum element in stack A, rotates it to the top, and pushes it to B. Once all but one element are in B, pulls them back to A in sorted order.

Efficient for nearly-sorted or small inputs (≤ ~20 elements). Degrades to O(n²) on random data.

### Chunk Sort (`--medium`)

Divides the index space into chunks of size √n. Pushes elements from A to B chunk by chunk, then pulls them back to A by always bringing the maximum of B to the top first.

Runs in O(n√n) on average. Good for mid-size inputs (20–200 elements).

### Radix Sort (`--complex`)

Sorts by binary index, bit by bit. For each bit position, elements with bit = 0 are pushed to B, elements with bit = 1 are rotated in A. After each pass, B is merged back into A.

Runs in O(n log n) regardless of input order. Best for large inputs (200–500+ elements).

### Adaptive Sort (`--adaptive`, default)

Measures the disorder of the input (fraction of inversions) and selects the cheapest algorithm:

```
disorder < 0.2   →  selection sort   (nearly sorted)
disorder < 0.3   →  chunk sort
disorder >= 0.3  →  radix sort
```

---

## Operations

| Op    | Effect                                          |
|-------|-------------------------------------------------|
| `sa`  | swap top two elements of A                      |
| `sb`  | swap top two elements of B                      |
| `ss`  | sa and sb simultaneously                        |
| `pa`  | push top of B onto A                            |
| `pb`  | push top of A onto B                            |
| `ra`  | rotate A up (top goes to bottom)                |
| `rb`  | rotate B up                                     |
| `rr`  | ra and rb simultaneously                        |
| `rra` | reverse rotate A (bottom goes to top)           |
| `rrb` | reverse rotate B                                |
| `rrr` | rra and rrb simultaneously                      |

---

## Benchmark Mode

Pass `--bench` to print profiling stats to stderr after sorting:

```bash
./push_swap --bench --complex 5 3 1 4 2
```

Output (stderr):
```
disorder: 0.70
strategy: COMPLEX (O(n log n))
total: 25
sa: 0  sb: 0  ss: 0  pa: 10  pb: 10
ra: 5  rb: 0  rr: 0  rra: 0  rrb: 0  rrr: 0
```

`--bench` does not affect stdout, so it can be combined with the checker:

```bash
./push_swap --bench 5 3 1 4 2 2>/dev/null | ./checker_linux 5 3 1 4 2
```

---

## Performance

Tested against the 42 grading thresholds:

```
--complex   100 numbers  →  ~1092 ops   (limit: 700 / 900 / 1100)
--complex   500 numbers  →  ~6784 ops   (limit: 5500 / 7000)
--adaptive  100 numbers  →  ~1150 ops
--adaptive  500 numbers  →  ~6784 ops
```

---

## Validation

```bash
# generate random input and verify output
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
```

---

## Resources
- [Medium article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Explanation Guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
