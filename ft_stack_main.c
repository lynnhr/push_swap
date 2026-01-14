/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <atchelde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:41:33 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/13 17:41:34 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_push_swap_operations.h"

int	main(void)
{
	t_stack	my_stack;
	t_node	*node;

	my_stack = ft_stack_new();
	ft_stack_push(&my_stack, 10);
	ft_stack_push(&my_stack, 20);
	ft_stack_push(&my_stack, 30);
	ft_stack_push(&my_stack, 40);
	ft_stack_push(&my_stack, 50);
	printf("Stack size: %d\n", ft_stack_size(&my_stack));
	printf("Stack bottom up:\n");
	ft_stack_print_bottom_up(&my_stack);
	printf("Stack top down:\n");
	ft_stack_print_top_down(&my_stack);
	node = ft_stack_pop(&my_stack);
	if (node)
	{
		printf("Popped value: %d\n", node->value);
		free(node);
	}
	printf("Stack size after pop: %d\n", ft_stack_size(&my_stack));
	t_node *n = ft_stack_pop(&my_stack);
	while (n)
	{
		printf("Before swap\n");
		// ft_stack_print_top_down(&my_stack);
		ft_swap_stack(&my_stack);
		printf("After swap\n");
		// ft_stack_print_top_down(&my_stack);
		printf("Head: %d\n", ft_stack_peek_head_value(&my_stack));
		free(n);
		n = ft_stack_pop(&my_stack);
	}
	free(n);
	ft_stack_free(&my_stack);
	t_stack s2 = ft_stack_new();
	ft_stack_pop(&s2);
	// ft_stack_print_top_down(&s2);
	ft_stack_free(&s2);
	return (0);
}
