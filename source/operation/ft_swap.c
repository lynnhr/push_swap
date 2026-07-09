/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:32:12 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 01:16:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

void	ft_sa(t_stack *a, t_bench *bench)
{
	ft_swap(a);
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b, t_bench *bench)
{
	ft_swap(b);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_swap(a);
	ft_swap(b);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
	ft_printf("ss\n");
}
