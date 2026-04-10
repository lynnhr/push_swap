/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 01:06:18 by marvin            #+#    #+#             */
/*   Updated: 2026/04/10 03:36:37 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap"

int	ft_find_min_pos(t_stack *a)
{
	int		min;
	t_node	*current;

	min = a->index;
	current = a;
	while(current->next)
	{
		if(current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

void	ft_bring_to_top(t_stack *a, int pos)
{
	int	size;

	size = ft_stack_size(a);
	if (pos <= size / 2)
		ft_ra(a);
	if (pos > size / 2)
		ft_rra(a);
}

void	ft_selection_sort(t_stack *a, t_stack *b)
{
	int	pos;

	pos = ft_find_min_pos(a);
	ft_bring_to_top(a, pos);
	ft_pb(a, b);
	ft_pa(a);
}