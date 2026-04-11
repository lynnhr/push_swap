/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 02:26:18 by marvin            #+#    #+#             */
/*   Updated: 2026/04/11 03:11:13 by marvin           ###   ########.fr       */
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

void	ft_chunk_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	chunks;
	int	i;
	
	size = ft_stack_size(a);
	chunks = ft_squareroot(size);
	i = 0;
	while (i < chunks)
	{
		i++;
	}

	
	
}