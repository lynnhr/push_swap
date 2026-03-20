/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:02:02 by marvin            #+#    #+#             */
/*   Updated: 2026/03/20 03:04:12 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include    "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	if (!ft_valid_input(argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
    if (!ft_check_duplicates(argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = ft_stack_new();
	b = ft_stack_new();
	ft_stack_free(&a);
	ft_stack_free(&b);
	return (0);
}