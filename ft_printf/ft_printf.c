/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <atchelde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:00:24 by atchelde          #+#    #+#             */
/*   Updated: 2025/12/13 18:00:26 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			rt_output;
	int			fd;

	rt_output = 0;
	fd = 1;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			rt_output += ft_putchar_fd(*str, fd);
		else
		{
			str++;
			rt_output += ft_helper(str, args, fd);
		}
		str++;
	}
	va_end(args);
	return (rt_output);
}

int	ft_helper(const char *str, va_list args, int fd)
{
	int	rt_output;

	rt_output = 0;
	if (*str == 'c')
		rt_output += ft_putchar_fd(va_arg(args, int), fd);
	else if (*str == 's')
		rt_output += ft_putstr_fd(va_arg(args, char *), fd);
	else if (*str == 'p')
		rt_output += ft_putptr_fd((unsigned long)va_arg(args, void *), fd);
	else if (*str == 'd' || *str == 'i')
		rt_output += ft_putnbr_fd(va_arg(args, int), fd);
	else if (*str == 'u')
		rt_output += ft_putunbr_fd((unsigned)va_arg(args, int), fd);
	else if (*str == 'x')
		rt_output += ft_puthex_fd((unsigned)va_arg(args, int), 1, fd);
	else if (*str == 'X')
		rt_output += ft_puthex_fd((unsigned)va_arg(args, int), 0, fd);
	else if (*str == '%')
		rt_output += ft_putchar_fd('%', fd);
	return (rt_output);
}
