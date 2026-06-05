/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:20:12 by marvin            #+#    #+#             */
/*   Updated: 2026/03/22 00:36:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	**ft_get_args(int argc, char **argv)
{
	int	skip;

	skip = 1;
	while (skip < argc && ft_flag(argv[skip]))
		skip++;
	if (argc == skip + 1)
		return (ft_split(argv[skip], ' '));
	return (argv + skip);
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

int	ft_valid_input(char **arr)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (arr[n])
		n++;
	while (arr[i])
	{
		if (!ft_valid_int(arr[i]))
			return (0);
		i++;
	}
	if (ft_check_duplicates(arr, n))
		return (0);
	return (1);
}
