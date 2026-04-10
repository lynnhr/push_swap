/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 03:03:59 by marvin            #+#    #+#             */
/*   Updated: 2026/04/11 02:17:36 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	ft_count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
}

int	ft_is_sorted(t_stack *a)
{
	t_node	*current;

	current = a->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	bits;
	int	bit;
	int	i;

	n = ft_stack_size(a);
	bits = ft_count_bits(n);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < n)
		{
			if (!((a->head->index >> bit) & 1))
				ft_pb(a, b);
			else
				ft_ra(a);
			i++;
		}
		while (ft_stack_size(b) > 0)
			ft_pa(a, b);
		bit++;
	}
}
