/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:44:28 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 21:41:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_atol(char *str)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_check_duplicates(char **argv, int n)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			num_i = ft_atol(argv[i]);
			num_j = ft_atol(argv[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
