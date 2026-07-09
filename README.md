*This project has been created as part of the 42 curriculum by atchelde, lhaydar*

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

### Small inputs (all strategies)

For n ≤ 5, every strategy delegates to a dedicated small sort: the minimums are
pushed to B, the remaining 3 elements are sorted in at most 2 operations, and B
is pushed back. Cost: ≤ 2 ops for 3 numbers, ≤ 10 ops for 5 numbers.

### Adaptive Sort (`--adaptive`, default)

Measures the disorder of the input (fraction of inverted pairs, computed before
any moves) and selects the cheapest algorithm:

```
disorder < 0.2    →  selection sort   (nearly sorted — behaves as O(n), see below)
disorder < 0.45   →  chunk sort       (O(n√n))
disorder >= 0.45  →  radix sort       (O(n log n))
```

**Threshold rationale:**

- **0.2 (low disorder):** on nearly-sorted input the current minimum is almost
  always already at (or next to) the top of A, so selection sort degenerates to
  the 2n push operations with almost no rotations. Its cost is O(n + k·n) where
  k is the number of displaced elements; for disorder < 0.2 this behaves
  linearly in the push_swap operation model (measured: 1028 ops ≈ 2n for 500
  nearly-sorted numbers).
- **0.45 (high disorder):** a uniformly random permutation has an expected
  disorder of exactly 0.5, with a spread of only ~0.5% at n = 500. A boundary
  placed exactly at 0.5 would make the chunk/radix choice a coin flip on random
  data, and the chunk path (~13000 ops at n = 500) risks exceeding the 12000-op
  limit. Moving the boundary to 0.45 means random inputs deterministically use
  radix sort, while chunk sort still handles genuinely partially-sorted inputs.
  The medium regime's complexity target still holds, since O(n log n) is within
  the O(n√n) bound.

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
./push_swap --bench --simple 5 4 3 2 1
```

Output (stderr):
```
[bench] disorder: 100.00%
[bench] strategy: Simple / O(n^2)
[bench] total_ops: 8
[bench] sa: 1 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 0 rb: 0 rr: 0 rra: 3 rrb: 0 rrr: 0
```

The disorder is printed as a percentage with two decimals (`0.00%` for a sorted
input, `100.00%` for a reverse-sorted one).

`--bench` does not affect stdout, so it can be combined with the checker:

```bash
./push_swap --bench 5 3 1 4 2 2>/dev/null | ./checker_linux 5 3 1 4 2
```

---

## Performance

Tested against the 42 grading thresholds (default/adaptive strategy):

```
3 numbers    →  1–2 ops     (sheet: 5 acceptable, 3 good)
5 numbers    →  6–9 ops     (sheet: 15 acceptable, 12 good)
100 numbers  →  1084 ops    (pass < 2000, good < 1500)
500 numbers  →  6784 ops    (pass < 12000, good < 8000)
```

The 100- and 500-number counts are deterministic on random input: disorder of a
random permutation is ~0.5, above the 0.45 threshold, so adaptive always picks
radix sort there.

---

## Testing

### Small inputs

```bash
ARG="2 1";       ./push_swap $ARG | wc -l; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1";     ./push_swap $ARG | wc -l; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l; ./push_swap --adaptive $ARG | ./checker_linux $ARG
```

### 100 random numbers — all strategies

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
echo "adaptive:"; ./push_swap $ARG | wc -l;           ./push_swap $ARG | ./checker_linux $ARG
echo "complex:";  ./push_swap --complex $ARG | wc -l; ./push_swap --complex $ARG | ./checker_linux $ARG
echo "medium:";   ./push_swap --medium $ARG | wc -l;  ./push_swap --medium $ARG | ./checker_linux $ARG
echo "simple:";   ./push_swap --simple $ARG | wc -l;  ./push_swap --simple $ARG | ./checker_linux $ARG
```

### 500 random numbers — bench mode

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --bench $ARG 2>bench.txt | ./checker_linux $ARG
cat bench.txt

./push_swap --bench --adaptive $ARG 2>&1 >/dev/null
./push_swap --bench --complex  $ARG 2>&1 >/dev/null
./push_swap --bench --simple   $ARG 2>&1 >/dev/null
```

### Memory leak checks (valgrind)

```bash
valgrind --leak-check=full ./push_swap 5 4 3 2 1
valgrind --leak-check=full ./push_swap 1 2 3
valgrind --leak-check=full ./push_swap abc
valgrind --leak-check=full ./push_swap 1 2 2
valgrind --leak-check=full "./push_swap" "5 3 1 4 2"
valgrind --leak-check=full ./push_swap $(shuf -i 0-999 -n 100 | tr '\n' ' ')
```

All runs should report `All heap blocks were freed -- no leaks are possible` and `ERROR SUMMARY: 0 errors`.

---

## Resources
- [Medium article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Explanation Guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
