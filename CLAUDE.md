# Push_swap — Claude Context File
*Paste this at the start of every new conversation to resume seamlessly.*

---

## Project
- 42 Beirut push_swap — group project: lhaydar + atchelde
- Language: C, strict 42 Norm (max 25 lines/function, vars declared at top, no globals)
- No bonus (checker not implemented)

---

## Current Status
### Completed ✅
- Stack structure (t_node: value, index, next — t_stack: head)
- All 11 operations (sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr)
- Input parsing + validation + quoted string handling
- Index assignment (ft_assign_indices)
- Disorder metric (ft_compute_disorder → double 0.0-1.0)
- Flag parsing (--simple, --medium, --complex, --adaptive, --bench)
- Radix sort O(n log n) — --complex
- Selection sort O(n²) — --simple
- Chunk sort O(n√n) — --medium
- Adaptive selector — --adaptive (default)
- Benchmark mode (--bench) — fully implemented ✅
  - All 11 operation signatures accept t_bench*
  - All sorting function signatures accept t_bench*
  - ft_sort and ft_run thread t_bench* through
  - ft_print_bench prints disorder/strategy/total/per-op to stderr

### Remaining TODO ⬜
- Final testing with checker_linux

---

## Performance
```
--complex  100 → ~1092 ops  (good ✓)
--complex  500 → ~6784 ops  (good ✓)
--medium   100 → ~1200 ops  (good ✓)
--medium   500 → ~13000 ops (slightly over, passes minimum)
--adaptive 100 → ~1150 ops  (good ✓)
--adaptive 500 → ~6784 ops  (good ✓)
```

---

## Adaptive Thresholds
```
disorder < 0.2  → selection sort  (O(n²), fast for nearly sorted)
disorder < 0.3  → chunk sort      (O(n√n))
disorder >= 0.3 → radix sort      (O(n log n))
```

---

## File Structure
```
push_swap/
├── Makefile
├── header/
│   ├── ft_stack.h          (t_node, t_stack structs + stack prototypes)
│   └── ft_push_swap.h      (all prototypes + t_strategy enum + t_bench struct)
├── source/
│   ├── main.c              (main, ft_parse_flags, ft_handle_error, ft_sort, ft_run)
│   ├── ft_bench.c          (ft_print_bench, ft_print_strategy, ft_print_ops_*)
│   ├── operation/
│   │   ├── ft_swap.c       (ft_swap, ft_sa, ft_sb, ft_ss)
│   │   ├── ft_push.c       (ft_push, ft_pa, ft_pb)
│   │   ├── ft_rotate.c     (ft_rotate, ft_ra, ft_rb, ft_rr)
│   │   └── ft_reverse_rotate.c (ft_reverse_rotate, ft_rra, ft_rrb, ft_rrr)
│   ├── stack/
│   │   ├── ft_stack_utils_a.c  (ft_stack_new, push, pop, peek)
│   │   └── ft_stack_utils_b.c  (ft_stack_size, print, free)
│   ├── parsing/
│   │   ├── ft_parsing.c
│   │   ├── ft_parsing_utils.c
│   │   ├── ft_parsing_flags.c
│   │   └── ft_populate_stack.c
│   └── sorting/
│       ├── ft_radix_sort.c     (ft_radix_sort, ft_count_bits, ft_is_sorted)
│       ├── ft_selection_sort.c (ft_selection_sort, ft_find_min_pos, ft_bring_to_top)
│       ├── ft_chunk_sort.c     (ft_chunk_sort, ft_push_chunks)
│       ├── ft_chunk_sort_helper.c (ft_squareroot, ft_find_max_index, ft_bring_max_to_top, ft_pull_back)
│       └── ft_adaptive_sort.c  (ft_adaptive_sort, ft_compute_disorder, ft_putdouble)
├── Libft/
└── ft_printf/
```

---

## Key Types (ft_push_swap.h)
```c
typedef enum e_strategy
{
    ADAPTIVE,
    SIMPLE,
    MEDIUM,
    COMPLEX
}   t_strategy;

typedef struct s_bench
{
    int sa; int sb; int ss;
    int pa; int pb;
    int ra; int rb; int rr;
    int rra; int rrb; int rrr;
    int total;
}   t_bench;
```

---

## main Flow
```c
int main(int argc, char **argv)
  → ft_parse_flags(argc, argv, &strategy, &bench)
  → ft_get_args(argc, argv) → args
  → ft_valid_input(args)
  → ft_init_stacks(&a, &b, args)
  → ft_run(&a, &b, strategy, bench)
      → ft_bzero(&bench_struct)
      → ft_compute_disorder(a)   // only if --bench
      → ft_sort(&a, &b, strategy, bench_ptr)
      → ft_print_bench(...)      // only if --bench
  → ft_cleanup(&a, &b, args, argc == 2)
```

---

## Benchmark Mode — Implemented
Operations accept `t_bench *bench` (NULL when not benchmarking):
```c
void ft_ra(t_stack *a, t_bench *bench)
{
    ft_rotate(a);
    if (bench)
    {
        bench->ra++;
        bench->total++;
    }
    ft_printf("ra\n");
}
```

ft_print_bench output (to stderr):
```
disorder: 0.70
strategy: COMPLEX (O(n log n))
total: 25
sa: 0  sb: 0  ss: 0  pa: 10  pb: 10
ra: 5  rb: 0  rr: 0  rra: 0  rrb: 0  rrr: 0
```

---

## Important Technical Notes
- ft_push MUST carry index: `dst->head->index = tmp->index` after push
- All errors → stderr (fd=2), all operations → stdout (fd=1), bench stats → stderr (fd=2)
- ft_printf doesn't support %f → use ft_putdouble(n, decimals, fd) helper
- ft_atol needed (ft_atoi truncates to int before overflow check)
- Quoted strings handled by ft_split in ft_get_args
- ft_get_args skips ALL flags before numbers
- t_bench* is always passed (never NULL) — ft_print_bench only called when --bench flag set

## Norminette Rules (already applied)
- Header comment must be `/* *** */` format, NOT `/*****/` — fixed across all source files
- Max 4 function arguments — ft_push_chunks had 5, fixed by computing size/chunk_size internally
- Ternaries forbidden — removed from ft_run, use if/else instead
