/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:00:00 by lhaydar           #+#    #+#             */
/*   Updated: 2026/07/09 00:00:00 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_sort_three(t_stack *a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = a->head->value;
	mid = a->head->next->value;
	bot = a->head->next->next->value;
	if (top > mid && mid < bot && top < bot)
		ft_sa(a, bench);
	else if (top > mid && mid > bot)
	{
		ft_sa(a, bench);
		ft_rra(a, bench);
	}
	else if (top > mid && top > bot)
		ft_ra(a, bench);
	else if (top < mid && mid > bot && top < bot)
	{
		ft_sa(a, bench);
		ft_ra(a, bench);
	}
	else
		ft_rra(a, bench);
}

void	ft_small_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	while (ft_stack_size(a) > 3)
	{
		ft_bring_to_top(a, ft_find_min_pos(a), bench);
		ft_pb(a, b, bench);
	}
	if (ft_stack_size(a) == 2 && !ft_is_sorted(a))
		ft_sa(a, bench);
	else if (ft_stack_size(a) == 3 && !ft_is_sorted(a))
		ft_sort_three(a, bench);
	while (ft_stack_size(b) > 0)
		ft_pa(a, b, bench);
}
