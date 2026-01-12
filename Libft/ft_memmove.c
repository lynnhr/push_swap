/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:15:18 by atchelde          #+#    #+#             */
/*   Updated: 2025/11/22 12:15:20 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest <= src)
	{
		i = 0;
		while ((size_t) i < n)
		{
			((char *)(dest))[i] = ((char *)(src))[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			((char *)(dest))[i] = ((char *)(src))[i];
			i--;
		}
	}
	return ((void *)(dest));
}
/*
int	main(void)
{
	char str[20] = "abcdef";
	ft_memmove(str + 2, str, 4);
	printf("%s\n", str);
}
*/
