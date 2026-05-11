/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:32:36 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 01:18:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*save;

	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	save = stack -> head;
	stack -> head = stack -> head -> next;
	current = stack -> head;
	while (current -> next)
		current = current -> next;
	current -> next = save;
	save -> next = NULL;
}

void	ft_ra(t_stack *a, t_bench *bench)
{
	ft_rotate(a);
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b, t_bench *bench)
{
	ft_rotate(b);
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
	ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_rotate(a);
	ft_rotate(b);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
	ft_printf("rr\n");
}
