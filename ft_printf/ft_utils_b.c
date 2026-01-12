/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <atchelde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:16:20 by atchelde          #+#    #+#             */
/*   Updated: 2025/12/22 20:16:22 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(unsigned long n, int fd)
{
	int	rt_output;

	rt_output = 0;
	if (! n)
		rt_output += ft_putstr_fd("(nil)", fd);
	else
	{
		rt_output += ft_putstr_fd("0x", fd);
		rt_output += ft_puthex_fd(n, 1, fd);
	}
	return (rt_output);
}

int	ft_puthex_fd(unsigned long n, int lower, int fd)
{
	char	*l_map;
	int		rem;
	int		rt_output;

	l_map = "abcdef";
	rem = n % 16;
	rt_output = 0;
	if (n >= 16)
		rt_output += ft_puthex_fd(n / 16, lower, fd);
	if (rem < 10)
		rt_output += ft_putnbr_fd(rem, fd);
	else
	{
		if (lower)
			rt_output += ft_putchar_fd(l_map[rem - 10], fd);
		else
			rt_output += ft_putchar_fd(l_map[rem - 10] - 32, fd);
	}
	return (rt_output);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	last_digit;
	int		rt_output;

	rt_output = 0;
	if (n > 0)
	{
		last_digit = n % 10 + '0';
		if (n / 10 != 0)
			rt_output += ft_putnbr_fd(n / 10, fd);
		rt_output += ft_putchar_fd(last_digit, fd);
	}
	else
		rt_output += ft_putchar_fd('0', fd);
	return (rt_output);
}
