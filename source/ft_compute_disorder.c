/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_disorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 00:23:08 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 14:33:11 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putdouble(double n, int decimals)
{
	int		integer_part;
	int		decimal_part;
	double	multiplier;
	int		i;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	integer_part = (int)n;
	ft_putnbr_fd(integer_part, 1);
	ft_putchar_fd('.', 1);
	multiplier = 1;
	i = 0;
	while (i < decimals)
	{
		multiplier *= 10;
		i++;
	}
	decimal_part = (int)((n - integer_part) * multiplier);
	ft_putnbr_fd(decimal_part, 1);
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
