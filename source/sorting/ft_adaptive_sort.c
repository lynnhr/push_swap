/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 00:41:12 by marvin            #+#    #+#             */
/*   Updated: 2026/04/12 02:31:18 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

void	ft_rotate_to_pos(t_stack *a, int pos)
{
	int	size;

	size = ft_stack_size(a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ft_ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			ft_rra(a);
	}
}

void	ft_insert_from_b(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		target;
	int		pos;

	target = b->head->index - 1;
	if (target < 0 || ft_stack_size(a) == 0)
	{
		ft_pa(a, b);
		if (target < 0 && ft_stack_size(a) > 1)
			ft_rra(a);
		return ;
	}
	current = a->head;
	pos = 0;
	while (current && current->index != target)
	{
		pos++;
		current = current->next;
	}
	if (!current)
		pos = 0;
	else
		pos++;          // ← add this, go one past target
	ft_rotate_to_pos(a, pos);
	ft_pa(a, b);
}

void	ft_linear_sort(t_stack *a, t_stack *b)
{
	// int	size;

	// size = ft_stack_size(a);
	while (ft_stack_size(a) > 0)
		ft_pb(a, b);
	while (ft_stack_size(b) > 0)
		ft_insert_from_b(a, b);
}

void	ft_adaptive_sort(t_stack *a, t_stack *b)
{
	double	disorder;

	disorder = ft_compute_disorder(a);
	if (disorder < 0.2)
		ft_linear_sort(a, b);
	else if (disorder < 0.5)
		ft_chunk_sort(a, b);
	else
		ft_radix_sort(a, b);
}
