/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 03:03:59 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 13:14:33 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
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
