#include "ft_push_swap.h"

static void	test_operations(void)
{
	t_stack	a;
	t_stack	b;

	a = ft_stack_new();
	b = ft_stack_new();
	ft_stack_push(&a, 5);
	ft_stack_push(&a, 3);
	ft_stack_push(&a, 8);
	ft_stack_push(&a, 1);

	ft_printf("=== OPERATIONS TEST ===\n");

	// rotate
	ft_printf("Initial:   "); ft_stack_print_top_down(&a);
	ft_ra(&a);
	ft_printf("After ra:  "); ft_stack_print_top_down(&a);
	ft_rra(&a);
	ft_printf("After rra: "); ft_stack_print_top_down(&a);

	// swap
	ft_sa(&a);
	ft_printf("After sa:  "); ft_stack_print_top_down(&a);

	// push between stacks
	ft_pb(&a, &b);
	ft_printf("After pb - a: "); ft_stack_print_top_down(&a);
	ft_printf("After pb - b: "); ft_stack_print_top_down(&b);
	ft_pa(&a, &b);
	ft_printf("After pa - a: "); ft_stack_print_top_down(&a);
	ft_printf("After pa - b: "); ft_stack_print_top_down(&b);

	// both stacks rotate
	ft_stack_push(&b, 9);
	ft_stack_push(&b, 7);
	ft_printf("Before rr - a: "); ft_stack_print_top_down(&a);
	ft_printf("Before rr - b: "); ft_stack_print_top_down(&b);
	ft_rr(&a, &b);
	ft_printf("After rr - a:  "); ft_stack_print_top_down(&a);
	ft_printf("After rr - b:  "); ft_stack_print_top_down(&b);
	ft_rrr(&a, &b);
	ft_printf("After rrr - a: "); ft_stack_print_top_down(&a);
	ft_printf("After rrr - b: "); ft_stack_print_top_down(&b);

	ft_stack_free(&a);
	ft_stack_free(&b);
}

static void	test_edge_cases(void)
{
	t_stack	a;
	t_stack	b;

	ft_printf("=== EDGE CASES TEST ===\n");

	// empty stack operations
	a = ft_stack_new();
	b = ft_stack_new();
	ft_printf("Operations on empty stack:\n");
	ft_ra(&a);
	ft_rra(&a);
	ft_sa(&a);
	ft_pb(&a, &b);
	ft_pa(&a, &b);
	ft_printf("No crash on empty stack\n");
	ft_stack_free(&a);
	ft_stack_free(&b);

	// single element
	a = ft_stack_new();
	b = ft_stack_new();
	ft_stack_push(&a, 42);
	ft_printf("Single element stack:\n");
	ft_ra(&a);
	ft_printf("After ra:  "); ft_stack_print_top_down(&a);
	ft_rra(&a);
	ft_printf("After rra: "); ft_stack_print_top_down(&a);
	ft_sa(&a);
	ft_printf("After sa:  "); ft_stack_print_top_down(&a);
	ft_stack_free(&a);
	ft_stack_free(&b);

	// two elements
	a = ft_stack_new();
	b = ft_stack_new();
	ft_stack_push(&a, 2);
	ft_stack_push(&a, 1);
	ft_printf("Two elements [1, 2]:\n");
	ft_sa(&a);
	ft_printf("After sa:  "); ft_stack_print_top_down(&a);
	ft_ra(&a);
	ft_printf("After ra:  "); ft_stack_print_top_down(&a);
	ft_rra(&a);
	ft_printf("After rra: "); ft_stack_print_top_down(&a);
	ft_stack_free(&a);
	ft_stack_free(&b);
}

static void	test_stack_structure(void)
{
	t_stack	a;

	ft_printf("=== STACK STRUCTURE TEST ===\n");

	// push and pop
	a = ft_stack_new();
	ft_stack_push(&a, 1);
	ft_stack_push(&a, 2);
	ft_stack_push(&a, 3);
	ft_printf("After 3 pushes: "); ft_stack_print_top_down(&a);
	ft_printf("Size: %d\n", ft_stack_size(&a));

	t_node *node = ft_stack_pop(&a);
	ft_printf("Popped: %d\n", node->value);
	free(node);
	ft_printf("After pop: "); ft_stack_print_top_down(&a);
	ft_printf("Size: %d\n", ft_stack_size(&a));

	// peek
	ft_printf("Peek value: %d\n", ft_stack_peek_head_value(&a));

	// free
	ft_stack_free(&a);
	ft_printf("After free - size: %d\n", ft_stack_size(&a));

	// NULL safety
	ft_stack_free(NULL);
	ft_stack_size(NULL);
	ft_printf("No crash on NULL\n");
}

int	main(void)
{
	test_stack_structure();
	ft_printf("\n");
	test_operations();
	ft_printf("\n");
	test_edge_cases();
	return (0);
}