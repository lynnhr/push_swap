#include "stack.h"

int main()
{
	t_stack my_stack = ft_stack_new();
	// ft_stack_print_bottom_up(&my_stack);
	ft_stack_push(&my_stack, 1);
	// ft_stack_print_bottom_up(&my_stack);
	ft_stack_push(&my_stack, 4);
	ft_stack_push(&my_stack, 6);
	ft_stack_push(&my_stack, 8);
	ft_stack_push(&my_stack, 10);
	// ft_stack_print_bottom_up(&my_stack);
	// ft_stack_print_top_down(&my_stack);
	// printf("%d\n", ft_stack_size(&my_stack));
	//ft_stack_pop(&my_stack);
	// ft_stack_print_bottom_up(&my_stack);
	// ft_stack_print_top_down(&my_stack);
	ft_stack_free(&my_stack);
	return (0);
}