/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:02:02 by marvin            #+#    #+#             */
/*   Updated: 2026/03/21 00:12:50 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	args = ft_get_args(argc, argv);
	if (!args || !ft_valid_input(args))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = ft_stack_new();
	b = ft_stack_new();
	ft_populate_stack(&a, args);
	ft_assign_indices(&a);
	ft_printf("values: ");
	ft_stack_print_top_down(&a);
	ft_printf("indices: ");
	ft_stack_print_indices(&a);
	if (argc == 2)
		ft_free_split(args);
	ft_stack_free(&a);
	ft_stack_free(&b);
	return (0);
}
