/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:20:12 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 21:17:16 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include	"ft_push_swap.h"

int	ft_valid_input_arr(char **arr)
{
	int	i;
	int	n;
	
	i = 0;
	n = 0;
	while (arr[n])
		n++;
	while(arr[i])
	{
		if (!ft_valid_int(arr[i]))
			return (0);
		i++;
	}
	if (ft_check_duplicates(arr, n))
		return (0);
	return (1);
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
		while(j < n)
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
	char **split;
	int result;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		result = ft_valid_input_arr(split);
		ft_free_split(split);
		return (result);
	}
	return (ft_valid_input_arr(argv + 1));
}