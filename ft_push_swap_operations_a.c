/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_operations_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:43:38 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/14 13:40:59 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_operations.h"

void	ft_swap_swap(t_stack *stack)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (ft_stack_size(stack) > 1)
	{
		temp_1 = ft_stack_pop(stack);
		temp_2 = ft_stack_pop(stack);
		ft_stack_push(stack, temp_1->value);
		ft_stack_push(stack, temp_2->value);
	}
	temp_1 = NULL;
	temp_2 = NULL;
	return ;
}

void	ft_swap_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_b;

	if (ft_stack_size(stack_b) != 0)
	{
		temp_b = ft_stack_pop(stack_b);
		ft_stack_push(stack_a, temp_b->value);
	}
	temp_b = NULL;
	return ;
}

void	ft_swap_rotate(t_stack *stack)
{
	t_node	*temp_head;
	t_node	*current;
	t_node	*next;
	t_stack	aux;

	aux = ft_stack_new();
	if (ft_stack_size(stack) > 1)
	{
		temp_head = ft_stack_pop(stack);
		current = stack->head;
		while (1)
		{
			ft_stack_push(&aux, ft_stack_peek_head_value(stack));
			next = current->next;
			if (! next)
				break ;
			free(current);
			current = next;
		}
		ft_stack_push(stack, temp_head->value);
		ft_swap_swap(stack);
		current = aux.head;
		while (current)
		{
			next = current->next;
			current = ft_stack_pop(&aux);
			ft_stack_push(stack, current->value);
			free(current);
			current = next;
		}
	}
	temp_head = NULL;
	current = NULL;
	return ;
}

// void	ft_swap_reverse_rotate(t_stack *stack)
// {

// }