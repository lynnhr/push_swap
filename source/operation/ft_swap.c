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
	t_node	*tmp1;
	t_node	*tmp2;

	if (!stack || ft_stack_size(stack) <= 1)
		return ;
	tmp1 = ft_stack_pop(stack);
	tmp2 = ft_stack_pop(stack);
	ft_stack_push(stack, tmp1->value);
	ft_stack_push(stack, tmp2->value);
	free(tmp1);
	free(tmp2);
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
