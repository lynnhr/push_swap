/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:47:34 by atchelde          #+#    #+#             */
/*   Updated: 2025/11/24 10:47:36 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(int n)
{
	long int	len;
	long int	nbr;

	len = 0;
	nbr = n;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		len;
	unsigned int	number;

	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		number = (unsigned int)(-(long)n);
	}
	else
		number = (unsigned int)n;
	if (n == 0)
		s[0] = '0';
	while (number > 0)
	{
		s[--len] = (number % 10) + '0';
		number = number / 10;
	}
	return (s);
}
