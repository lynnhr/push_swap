/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:32:40 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 14:33:34 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*save;
	t_node	*current;

	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	current = stack->head;
	while (current->next->next)
		current = current->next;
	save = current->next;
	current->next = NULL;
	save->next = stack->head;
	stack->head = save;
}

void	ft_rra(t_stack *a, t_bench *bench)
{
	ft_reverse_rotate(a);
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *b, t_bench *bench)
{
	ft_reverse_rotate(b);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
	ft_printf("rrr\n");
}
