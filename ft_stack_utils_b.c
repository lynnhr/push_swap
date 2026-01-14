/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:32 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/12 15:18:33 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_size(t_stack *stack)
{
	t_node	*current;
	int		rt_length;

	current = stack->head;
	rt_length = 0;
	while (current)
	{
		rt_length++;
		current = current->next;
	}
	return (rt_length);
}

void	ft_stack_print_bottom_up(t_stack *stack)
{
	t_node	*current;
	t_stack	aux;

	aux = ft_stack_new();
	current = stack->head;
	while (current)
	{
		ft_stack_push(&aux, current->value);
		current = current->next;
	}
	current = aux.head;
	while (current)
	{
		printf("%d", current->value);
		current = current->next;
		if (current)
			printf("->");
	}
	printf("\n");
	free(current);
	ft_stack_free(&aux);
	return ;
}

void	ft_stack_print_top_down(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("%d", current->value);
		current = current->next;
		if (current)
			printf("<-");
	}
	printf("\n");
	free(current);
}

void	ft_stack_free(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		stack->head = current->next;
		free(current);
		current = stack->head;
	}
	current = NULL;
	return ;
}
