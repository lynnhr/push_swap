/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:23:43 by atchelde          #+#    #+#             */
/*   Updated: 2025/11/22 13:23:44 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*temp;
	size_t			i;

	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (! ptr)
		return (NULL);
	temp = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}
