/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 23:50:14 by marvin            #+#    #+#             */
/*   Updated: 2026/04/12 00:31:11 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	ft_squareroot(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

int	ft_find_max_index(t_stack *b)
{
	t_node	*current;
	int		max;

	current = b->head;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

void	ft_bring_max_to_top(t_stack *b)
{
	int		max_idx;
	int		pos;
	int		size;
	t_node	*current;

	max_idx = ft_find_max_index(b);
	size = ft_stack_size(b);
	current = b->head;
	pos = 0;
	while (current->index != max_idx)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			ft_rb(b);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			ft_rrb(b);
	}
}

void	ft_pull_back(t_stack *a, t_stack *b)
{
	while (ft_stack_size(b) > 0)
	{
		ft_bring_max_to_top(b);
		ft_pa(a, b);
	}
}
