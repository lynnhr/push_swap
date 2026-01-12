/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <atchelde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:09:37 by atchelde          #+#    #+#             */
/*   Updated: 2025/12/13 18:09:38 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	rt_output;

	rt_output = 0;
	if (! s)
		rt_output += ft_putstr_fd("(null)", fd);
	else
	{
		while (*s)
		{
			rt_output += ft_putchar_fd(*s, fd);
			s++;
		}
	}
	return (rt_output);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	last_digit;
	int		rt_output;

	rt_output = 0;
	if (n == -2147483648)
		rt_output += (ft_putstr_fd("-2147483648", fd));
	else if (n < 0)
	{
		rt_output += ft_putchar_fd('-', fd);
		rt_output += ft_putnbr_fd(-1 * n, fd);
	}
	else if (n > 0)
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
