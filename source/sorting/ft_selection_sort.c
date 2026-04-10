/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 01:06:18 by marvin            #+#    #+#             */
/*   Updated: 2026/04/11 02:19:02 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	ft_find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min_idx;
	int		min_pos;
	int		pos;

	current = a->head;
	min_idx = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_idx)
		{
			min_idx = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	ft_bring_to_top(t_stack *a, int pos)
{
	int	size;
	int	rotations;

	size = ft_stack_size(a);
	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations-- > 0)
			ft_ra(a);
	}
	else
	{
		rotations = size - pos;
		while (rotations-- > 0)
			ft_rra(a);
	}
}

void	ft_selection_sort(t_stack *a, t_stack *b)
{
	int	pos;

	while (ft_stack_size(a) > 1)
	{
		pos = ft_find_min_pos(a);
		ft_bring_to_top(a, pos);
		ft_pb(a, b);
	}
	while (ft_stack_size(b) > 0)
		ft_pa(a, b);
}
