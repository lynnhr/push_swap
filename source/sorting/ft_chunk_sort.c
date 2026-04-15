/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 02:26:18 by marvin            #+#    #+#             */
/*   Updated: 2026/04/12 16:58:39 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

void	ft_push_chunks(t_stack *a, t_stack *b, int size, int chunk_size)
{
	int	threshold;
	int	i;

	threshold = chunk_size;
	while (ft_stack_size(a) > 0)
	{
		i = 0;
		while (i < size && a->head)
		{
			if (a->head->index < threshold)
				ft_pb(a, b);
			else
				ft_ra(a);
			i++;
		}
		threshold += chunk_size;
	}
}

void	ft_chunk_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk_size;

	size = ft_stack_size(a);
	chunk_size = ft_squareroot(size);
	ft_push_chunks(a, b, size, chunk_size);
	ft_pull_back(a, b);
}
