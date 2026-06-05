/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:32 by atchelde          #+#    #+#             */
/*   Updated: 2026/03/21 00:15:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	t_node	*current;
	int		rt_length;

	if (!stack)
		return (0);
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
		ft_printf("%d", current->value);
		current = current->next;
		if (current)
			ft_printf("->");
	}
	ft_printf("\n");
	ft_stack_free(&aux);
	return ;
}

void	ft_stack_print_top_down(t_stack *stack)
{
	t_node	*current;

	if (!stack)
	{
		ft_printf("\n");
		return ;
	}
	current = stack->head;
	while (current)
	{
		ft_printf("%d", current->value);
		if (current->next)
			ft_printf("<-");
		current = current->next;
	}
	ft_printf("\n");
}

void	ft_stack_free(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		stack->head = current->next;
		free(current);
		current = stack->head;
	}
	current = NULL;
	stack->head = NULL;
	return ;
}
