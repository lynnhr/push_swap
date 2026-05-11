/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 00:41:12 by marvin            #+#    #+#             */
/*   Updated: 2026/04/12 17:13:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putdouble(double n, int decimals, int fd)
{
	int		integer_part;
	int		decimal_part;
	double	multiplier;
	int		i;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	integer_part = (int)n;
	ft_putnbr_fd(integer_part, fd);
	ft_putchar_fd('.', fd);
	multiplier = 1;
	i = 0;
	while (i < decimals)
	{
		multiplier *= 10;
		i++;
	}
	decimal_part = (int)((n - integer_part) * multiplier);
	ft_putnbr_fd(decimal_part, fd);
}

double	ft_compute_disorder(t_stack *a)
{
	double		mistakes;
	double		total_pairs;
	t_node		*current1;
	t_node		*current2;

	mistakes = 0;
	total_pairs = 0;
	current1 = a->head;
	while (current1)
	{
		current2 = current1->next;
		while (current2)
		{
			total_pairs += 1;
			if (current1->value > current2->value)
				mistakes += 1;
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	return (mistakes / total_pairs);
}

void	ft_adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	double	disorder;

	disorder = ft_compute_disorder(a);
	if (disorder == 0.0)
		return ;
	else if (disorder < 0.2)
		ft_selection_sort(a, b, bench);
	else if (disorder < 0.3)
		ft_chunk_sort(a, b, bench);
	else
		ft_radix_sort(a, b, bench);
}
