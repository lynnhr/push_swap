/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 03:03:59 by marvin            #+#    #+#             */
/*   Updated: 2026/03/22 01:55:14 by marvin           ###   ########.fr       */
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

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;
	t_node	*current;
	
	current = a -> head;
	i = 0;
	bits = ft_count_bits(a->value);
	while( i <= bits)
	{
		while(current)
		{
			if()
			current = current->next;
		}
		current-> value >> 1;
		i++;
	}
}