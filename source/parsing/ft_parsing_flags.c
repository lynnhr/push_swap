/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:05:45 by marvin            #+#    #+#             */
/*   Updated: 2026/03/22 00:56:45 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	ft_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	if (ft_strncmp(str, "--bench", 8) == 0)
		return (1);
	return (0);
}

t_strategy	ft_get_strategy(char *flag)
{
	if (ft_strncmp(flag, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(flag, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(flag, "--complex", 10) == 0)
		return (COMPLEX);
	return (ADAPTIVE);
}
