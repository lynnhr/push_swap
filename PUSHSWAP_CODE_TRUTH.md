# PUSHSWAP_CODE_TRUTH.md
Interview-prep ground truth. Every claim below is quoted from the actual
source. Where CLAUDE.md disagrees with the code, **the code wins** and I flag it.

---

## 1. DATA STRUCTURES

`header/ft_stack.h`:
```c
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *head;
}   t_stack;
```

- **Singly linked.** Each node has only a `*next`; there is no `*prev` and no
  tail pointer. `t_stack` is just a head pointer.
- A node carries exactly two data fields: `value` (the raw parsed int) and
  `index` (its 0..n-1 rank — see §3). Nothing else.
- "Top of stack" = `head`. Push/pop happen at the head (LIFO).

`t_bench` (in `header/ft_push_swap.h`) is a plain counter struct — one int per
operation plus `total` and a `silent` flag:
```c
typedef struct s_bench
{
    int sa; int sb; int ss;
    int pa; int pb;
    int ra; int rb; int rr;
    int rra; int rrb; int rrr;
    int total;
    int silent;   // 1 => --count mode: suppress op printing, only print total
}   t_bench;
```
> Note: CLAUDE.md's copy of `t_bench` is stale — it omits `silent`. The real
> struct has it.

Strategy enum:
```c
typedef enum e_strategy { ADAPTIVE, SIMPLE, MEDIUM, COMPLEX } t_strategy;
```

---

## 2. PARSING & VALIDATION

### Argument gathering — `source/parsing/ft_parsing.c`
```c
char	**ft_get_args(int argc, char **argv)
{
    int	skip;

    skip = 1;
    while (skip < argc && ft_flag(argv[skip]))
        skip++;
    if (argc == skip + 1)
        return (ft_split(argv[skip], ' '));   // single (possibly quoted) arg
    return (argv + skip);                      // multiple bare args, no copy
}
```
- Flags are skipped first. If exactly one non-flag arg remains, it's treated as
  a **quoted string** `"3 5 1"` and `ft_split` on spaces (heap-allocated).
- Otherwise it returns a pointer *into* `argv` (not allocated). This split-vs-
  not-split distinction is the source of a cleanup bug — see §10.

### Integer validation — `ft_valid_int`
```c
int	ft_valid_int(char *str)
{
    int i; long n;

    i = 0;
    if (!str || str[i] == '\0')
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '\0')          // lone "+" or "-" => invalid
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i])) // any non-digit => invalid
            return (0);
        i++;
    }
    n = ft_atol(str);
    if (n > 2147483647 || n < -2147483648)   // INT overflow check
        return (0);
    return (1);
}
```
- Non-integers (letters, symbols) rejected by the `ft_isdigit` loop.
- Overflow is caught by parsing into a `long` (`ft_atol`) and comparing against
  INT_MAX / INT_MIN. This is why `ft_atol` exists — `ft_atoi` would truncate
  before you could see the overflow.

### `ft_atol` — `source/parsing/ft_parsing_utils.c`
```c
long	ft_atol(char *str)
{
    long n; int sign; int i;

    n = 0; sign = 1; i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-') sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        n = n * 10 + (str[i] - '0');   // accumulates into long
    return (n * sign);
}
```
> **Gap:** `ft_atol` itself has no overflow guard. A string with ~19+ digits
> overflows `long` (UB) *before* the INT range check can reject it. In practice
> it still usually rejects such inputs, but you can't claim it's rigorous.

### Duplicates — `ft_check_duplicates`
```c
i = 0;
while (i < n) {
    j = i + 1;
    while (j < n) {
        num_i = ft_atol(argv[i]);
        num_j = ft_atol(argv[j]);
        if (num_i == num_j) return (1);
        j++;
    }
    i++;
}
return (0);
```
- Plain **O(n²)** pairwise compare (re-parses with `ft_atol` on every inner
  iteration — inefficient but correct).

### Top-level flow — `ft_valid_input`
Counts args, validates every one, then checks duplicates. Returns 0 on any
failure.

### stdout vs stderr / exit behavior — `source/main.c`
```c
int	ft_handle_error(char **args, int is_split)
{
    ft_putstr_fd("Error\n", 2);        // Error => stderr (fd 2)
    if (is_split) ft_free_split(args);
    return (1);
}
```
- **`Error\n` goes to stderr.** Operations go to stdout (`ft_printf`, fd 1).
  Bench stats go to stderr (fd 2).
- `main` returns `ft_handle_error(...)` which returns 1 → **exit code 1** on
  bad input. Valid runs return 0.
- Early exits that print nothing and return 0: `argc < 2`, and a single flag
  with no numbers (`if (ft_flag(argv[1]) && argc == 2) return (0);`).

---

## 3. INDEX NORMALIZATION (value → 0..n-1 rank)

`source/parsing/ft_populate_stack.c`:
```c
void	ft_assign_indices(t_stack *a)
{
    t_node *current; t_node *checker; int count;

    current = a->head;
    while (current) {
        count = 0;
        checker = a->head;
        while (checker) {
            if (current->value > checker->value)  // count how many are smaller
                count++;
            checker = checker->next;
        }
        current->index = count;   // rank = number of values below it
        current = current->next;
    }
}
```
- **O(n²)**, rank-by-counting. NOT a sorted-copy approach. Each node's index =
  how many nodes hold a strictly smaller value → gives a dense 0..n-1 ranking.
- After this, every sort works purely on `index`, never on `value`.

Population (`ft_populate_stack`) pushes args back-to-front with `ft_atoi` so the
first CLI number ends up on top:
```c
while (args[i]) i++;   i--;
while (i >= 0) { ft_stack_push(a, ft_atoi(args[i])); i--; }
```
> `ft_atoi` is safe here only because `ft_valid_int` already range-checked.

---

## 4. DISORDER METRIC

`source/sorting/ft_adaptive_sort.c`:
```c
double	ft_compute_disorder(t_stack *a)
{
    double mistakes; double total_pairs;
    t_node *current1; t_node *current2;

    mistakes = 0; total_pairs = 0;
    current1 = a->head;
    while (current1) {
        current2 = current1->next;
        while (current2) {
            total_pairs += 1;
            if (current1->value > current2->value)  // out-of-order pair
                mistakes += 1;
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return (mistakes / total_pairs);
}
```
- **Yes — it counts inversions.** For every ordered pair (i before j), if
  `value[i] > value[j]` that's one "mistake."
- `total_pairs` = n(n-1)/2 (every pair counted once).
- **Formula: disorder = inversions / total_pairs**, a ratio in [0,1].
  0.0 = fully sorted, ~1.0 = reverse sorted.
> **Gap:** for n ≤ 1, `total_pairs == 0` → `0.0/0.0` = **NaN**. The sort path is
> safe (see §5/§8), but `--bench` calls this directly on any size — a 1-element
> `--bench` run computes NaN.

---

## 5. ADAPTIVE SELECTOR

Two gates, in two different places.

### Gate A — "already sorted?" lives in `ft_sort` (main.c), not the selector:
```c
void	ft_sort(t_stack *a, t_stack *b, t_strategy strategy, t_bench *bench)
{
    if (ft_is_sorted(a))    // zero-ops exit for ALL strategies
        return ;
    if (strategy == COMPLEX)      ft_radix_sort(a, b, bench);
    else if (strategy == SIMPLE)  ft_selection_sort(a, b, bench);
    else if (strategy == MEDIUM)  ft_chunk_sort(a, b, bench);
    else                          ft_adaptive_sort(a, b, bench);
}
```
So **yes, "already sorted" is checked first and returns with zero operations**,
for every strategy — not just adaptive.

### Gate B — the adaptive branch itself (`ft_adaptive_sort`):
```c
void	ft_adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
    double disorder;

    disorder = ft_compute_disorder(a);
    if (disorder == 0.0)          ft_selection_sort... NO — returns:
        return ;
    else if (disorder < 0.2)      ft_selection_sort(a, b, bench);
    else if (disorder < 0.5)      ft_chunk_sort(a, b, bench);
    else                          ft_radix_sort(a, b, bench);
}
```
Exact decision table:
| disorder            | strategy chosen        |
|---------------------|------------------------|
| `== 0.0`            | return, 0 ops          |
| `< 0.2`             | selection sort O(n²)   |
| `< 0.5`             | chunk sort O(n√n)      |
| `>= 0.5`            | radix sort O(n log n)  |

- **Thresholds confirmed: 0.2 and 0.5.**
- **There are NO size thresholds.** CLAUDE.md claims "size thresholds AND
  disorder thresholds" — that is wrong. The only input to the decision is the
  disorder ratio. Don't say "for n < X" in the interview; the code never looks
  at n here.
> Minor inefficiency: in `--bench` mode disorder is computed once in `ft_run`
> for display, then **again** inside `ft_adaptive_sort`. Two O(n²) passes.

---

## 6. THE THREE SORTS

### Selection sort — `source/sorting/ft_selection_sort.c`
```c
void	ft_selection_sort(t_stack *a, t_stack *b, t_bench *bench)
{
    int pos;

    while (ft_stack_size(a) > 1) {
        pos = ft_find_min_pos(a);       // position of smallest index in a
        ft_bring_to_top(a, pos, bench); // rotate it to the top
        ft_pb(a, b, bench);             // push it to b
    }
    while (ft_stack_size(b) > 0)        // b is now descending; pa back
        ft_pa(a, b, bench);
}
```
`ft_find_min_pos` walks `a`, tracking the position of the minimum `index`.
**ra vs rra is decided in `ft_bring_to_top` by which half `pos` is in:**
```c
size = ft_stack_size(a);
if (pos <= size / 2) { rotations = pos;        while (rotations-- > 0) ft_ra(a, bench); }
else                 { rotations = size - pos; while (rotations-- > 0) ft_rra(a, bench); }
```
Top half → rotate up (`ra`); bottom half → reverse-rotate (`rra`). Fewest moves.

### Chunk sort — `source/sorting/ft_chunk_sort.c` (+ helper)
```c
void	ft_push_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
    int size; int chunk_size; int threshold; int i;

    size = ft_stack_size(a);
    chunk_size = ft_squareroot(size);   // chunk size = ceil(sqrt(n))
    threshold = chunk_size;
    while (ft_stack_size(a) > 0) {
        i = 0;
        while (i < size && a->head) {
            if (a->head->index < threshold)  ft_pb(a, b, bench); // in-chunk => push
            else                             ft_ra(a, bench);    // else rotate past
            i++;
        }
        threshold += chunk_size;         // widen to next chunk band
    }
}
```
- **Chunk size = √n**, computed by `ft_squareroot` (`while (i*i < n) i++;` →
  ceiling of the square root). NOT hardcoded.
- Elements whose index falls in the current chunk band get `pb`'d to b; others
  get `ra`'d to cycle past. Threshold grows by one chunk each outer pass.

**How they come back (`ft_pull_back` in ft_chunk_sort_helper.c):** by
repeatedly finding the **max index in b** and rotating it to b's top, then `pa`:
```c
void	ft_pull_back(t_stack *a, t_stack *b, t_bench *bench)
{
    while (ft_stack_size(b) > 0) {
        ft_bring_max_to_top(b, bench);   // find max index, rb/rrb it to top
        ft_pa(a, b, bench);              // push largest back first
    }
}
```
`ft_bring_max_to_top` mirrors selection's optimization — `rb` if the max is in
the top half of b, `rrb` if in the bottom half. Pushing largest-first means `a`
ends ascending. (This is a **find-max** pull-back, not a value comparison.)

### Radix sort (LSD binary) — `source/sorting/ft_radix_sort.c`
```c
void	ft_radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
    int n; int bits; int bit; int i;

    n = ft_stack_size(a);
    bits = ft_count_bits(n);         // number of bits to represent n
    bit = 0;
    while (bit < bits) {
        i = 0;
        while (i < n) {
            if (!((a->head->index >> bit) & 1))  ft_pb(a, b, bench); // bit==0 => to b
            else                                 ft_ra(a, bench);    // bit==1 => keep in a
            i++;
        }
        while (ft_stack_size(b) > 0)             ft_pa(a, b, bench);  // pull all back
        bit++;
    }
}
```
- Works on `index` (0..n-1), so a fixed, small number of bits.
- **Max bits** = `ft_count_bits(n)` — `while (n >> bits) bits++;` counts bits of
  the *count* n. Since every index < n, that's enough (it can be one iteration
  more than strictly needed, but never fewer — safe).
- **bit == 0 → `pb` to stack b. bit == 1 → `ra` (kept in a, rotated to bottom).**
  After each pass, everything in b is `pa`'d back. Stable LSD radix → sorted in
  `bits` passes, O(n log n) ops.

---

## 7. OPERATIONS

11 ops exist (sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr). **Which are actually
used per strategy:**

| strategy   | ops used                          | never used            |
|------------|-----------------------------------|-----------------------|
| selection  | `ra rra pb pa`                    | swaps, rb/rr/rrr...   |
| chunk      | `pb ra` (out) + `rb rrb pa` (back)| swaps, rra, rr...     |
| radix      | `pb ra pa`                        | swaps, rb, rrb...     |

> **The swap family (sa/sb/ss) is never called by any sort.** It's implemented
> and counted, but dead in practice. See §10 — and note swap has a latent bug.

Pointer manipulation example — `ft_ra` / `ft_rotate` (`ft_rotate.c`):
```c
void	ft_rotate(t_stack *stack)
{
    t_node *current; t_node *save;

    if (!stack || ft_stack_size(stack) <= 1)
        return ;
    save = stack->head;                 // detach old head
    stack->head = stack->head->next;    // 2nd node becomes new head
    current = stack->head;
    while (current->next)               // walk to the last node
        current = current->next;
    current->next = save;               // old head goes to the tail
    save->next = NULL;
}

void	ft_ra(t_stack *a, t_bench *bench)
{
    ft_rotate(a);
    if (bench) { bench->ra++; bench->total++; }
    if (!bench || !bench->silent)
        ft_printf("ra\n");
}
```
Rotate = move top element to the bottom by relinking pointers (no data copy).
Because it relinks whole nodes, `index` is preserved. (Contrast with swap, §10.)

---

## 8. EDGE CASES FROM CODE

- **Empty input** (`./push_swap` alone): `argc < 2` → `return (0)`, prints
  nothing. An empty quoted string `""` splits to an empty array → validation
  passes vacuously → `ft_is_sorted` on empty stack returns 1 → 0 ops, exit 0.
- **Single element**: `ft_is_sorted` returns 1 (loop condition `current->next`
  fails immediately) → `ft_sort` returns, 0 ops. *But* `--bench` on 1 element
  hits the NaN divide in `ft_compute_disorder` (§4).
- **Already sorted**: caught by `ft_is_sorted` in `ft_sort` → 0 ops, every
  strategy. Adaptive also has its own `disorder == 0.0` early return.
- **Reverse sorted**: disorder ≈ 1.0 → adaptive picks radix. Works generically.
- **2 and 3 elements**: **there is NO hardcoded `sort_three`/`sort_two`.** Small
  n is handled by whatever generic sort runs. `ft_is_sorted` first-checks catch
  the already-sorted cases; otherwise e.g. radix runs with `bits =
  ft_count_bits(2 or 3)`. It's correct but not optimal-op-count for n=3 the way
  a hand-tuned sort_three would be — be ready to admit that.

`ft_is_sorted` (radix file) compares **values**, not indices:
```c
while (current && current->next) {
    if (current->value > current->next->value) return (0);
    current = current->next;
}
return (1);
```

---

## 9. BENCHMARK MODE

Threading: `ft_run` (main.c) declares one `t_bench bench` on the stack, zeroes
it, and passes `&bench` down through `ft_sort` into every op. Each op increments
its own counter + `total` **only if `bench` is non-NULL**, and prints its name
**unless `bench->silent`**:
```c
void	ft_pb(t_stack *a, t_stack *b, t_bench *bench)
{
    ft_push(a, b);
    if (bench) { bench->pb++; bench->total++; }
    if (!bench || !bench->silent)
        ft_printf("pb\n");
}
```
Three run modes (`do_bench` int in `ft_run`):
- `0` normal — ops printed to stdout, no stats.
- `1` (`--bench`) — disorder computed, full stats printed to **stderr**.
- `2` (`--count`) — `bench.silent = 1`, ops **not** printed, only total count to
  stderr via `ft_print_count`.

`--bench` stderr output (`ft_bench.c`), exact format:
```
[bench] disorder: 70.00%
[bench] strategy: Complex / O(n log n)
[bench] total_ops: 25
[bench] sa: 0 sb: 0 ss: 0 pa: 10 pb: 10
[bench] ra: 5 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```
- disorder is printed as `disorder * 100` with 2 decimals via `ft_putdouble`
  (ft_printf has no `%f`). Strategy string for ADAPTIVE is chosen from the
  disorder value at print time (`< 0.2` → O(n), `< 0.5` → O(n√n), else
  O(n log n)).
- `--count` output is just the integer total + newline to stderr.

---

## 10. HONEST GAPS (know these before the interviewer does)

1. **`ft_swap` destroys `index`.** `ft_swap.c` pops both nodes and re-pushes by
   `value` only (`ft_stack_push` sets `value` and `next`, never `index`):
   ```c
   tmp1 = ft_stack_pop(stack); tmp2 = ft_stack_pop(stack);
   ft_stack_push(stack, tmp1->value);   // index lost!
   ft_stack_push(stack, tmp2->value);
   ```
   Since all sorts operate on `index`, calling sa/sb/ss would corrupt sorting.
   It's only safe because **no sort uses swap** (§7). If asked "why no swap in
   sort_three," the honest answer is: not implemented safely, so avoided.

2. **Split cleanup leak with flags.** `is_split` is decided by `argc == 2`
   (main.c passes `argc == 2` to `ft_cleanup`/`ft_handle_error`), but the actual
   split happens whenever `argc == skip + 1` (ft_get_args). With a flag +
   quoted string, e.g. `./push_swap --complex "3 5 1"`: `argc == 3`, a split
   *is* allocated, but `argc == 2` is false → the split array is **never
   freed** → memory leak. Bare-multi-arg and single-quoted-no-flag cases are
   fine; only flag+quoted leaks.

3. **`ft_atol` can overflow `long`** on ~19+ digit strings before the INT check
   runs (§2) — technically UB, not a clean rejection.

4. **NaN disorder for n ≤ 1 under `--bench`** (§4): `ft_compute_disorder` divides
   by `total_pairs == 0`.

5. **Disorder computed twice** in adaptive+bench (once in `ft_run`, once in
   `ft_adaptive_sort`) — wasteful O(n²) duplication.

6. **`ft_count_bits(n)` uses the count, not max index.** Correct (indices < n)
   but can do one redundant pass for exact powers of two. Easy to defend, just
   know it's `bits(n)` not `bits(n-1)`.

7. **No `sort_three` / small-n special case** (§8) — op counts for n=3 aren't
   optimal.

8. **`ft_get_args` returns a pointer into `argv`** for the multi-arg case (no
   allocation) — fine, but it's why the split/non-split cleanup flag exists and
   why bug #2 is easy to trip.

9. **Naming/dead code:** `ft_stack_peek_head_value` returns `INT_MAX` for an
   empty stack (unused), several print helpers (`ft_stack_print_top_down`,
   `ft_stack_print_indices`, `ft_stack_print_bottom_up`) are debug-only and
   unused in the sort path. `ft_squareroot` returns the *ceiling* of the root
   despite the plain name.
