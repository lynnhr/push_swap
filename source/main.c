/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:02:02 by marvin            #+#    #+#             */
/*   Updated: 2026/03/21 02:59:25 by marvin           ###   ########.fr       */
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
		if (argc == 2)
			ft_free_split(args);
		return (1);
	}
	ft_init_stacks(&a, &b, args);
	ft_printf("values:  ");
	ft_stack_print_top_down(&a);
	ft_printf("indices: ");
	ft_stack_print_indices(&a);
	ft_printf("disorder: ");
	ft_putdouble(ft_compute_disorder(&a), 2);
	ft_printf("\n");
	ft_cleanup(&a, &b, args, argc == 2);
	return (0);
}
