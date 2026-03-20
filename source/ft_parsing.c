/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:20:12 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 03:05:18 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include	"ft_push_swap.h"
#include	"ft_stack.h"

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

int	ft_valid_int(char *str)
{
	int		i;
	long	n;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	n = ft_atol(str);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	ft_check_duplicates(char **argv, int n)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while(i < n)
	{
		j = i + 1;
		while(j < i)
		{
			num_i = ft_atol(argv[i]);
			num_j = ft_atol(argv[j]);
			if (num_i ==  num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid_input(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_valid_int(argv[i]))
			return (0);
		i++;
	}
	if (ft_check_duplicates(argv + 1, argc - 1))
		return (0);
	return (1);
}