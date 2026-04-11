/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:02:02 by marvin            #+#    #+#             */
/*   Updated: 2026/04/12 00:19:10 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	char		**args;
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			bench;
	int			i;

	i = 1;
	bench = 0;
	if (argc < 2)
		return (0);
	if (ft_flag(argv[1]) && argc == 2)
		return (0);
	strategy = ADAPTIVE;
	while (i < argc && ft_flag(argv[i]))
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			bench = 1;
		else
			strategy = ft_get_strategy(argv[i]);
		i++;
	}
	args = ft_get_args(argc, argv);
	if (!args || !ft_valid_input(args))
	{
		ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			ft_free_split(args);
		return (1);
	}
	ft_init_stacks(&a, &b, args);
	(void)bench;
	if (!ft_is_sorted(&a))
	{
		if (strategy == COMPLEX)
			ft_radix_sort(&a, &b);
		else if (strategy == SIMPLE)
			ft_selection_sort(&a, &b);
		else if (strategy == MEDIUM)
			ft_chunk_sort(&a, &b);
	}
	ft_cleanup(&a, &b, args, argc == 2);
	return (0);
}
