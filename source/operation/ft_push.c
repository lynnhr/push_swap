/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 02:30:36 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 13:06:25 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push(t_stack *src, t_stack *dest)
{
	t_node	*tmp;

	if (!src || !src->head)
		return ;
	tmp = ft_stack_pop(src);
	ft_stack_push(dest, tmp->value);
	dest->head->index = tmp->index;
	free(tmp);
}

void	ft_pa(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_push(b, a);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
	ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_push(a, b);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
	ft_printf("pb\n");
}
