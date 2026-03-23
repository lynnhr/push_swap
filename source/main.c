/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaydar <lhaydar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:02:02 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 13:01:51 by lhaydar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (argc < 2)
		return (0);
	bench = 0;
	(void)bench;
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
	ft_printf("strategy: %d\n", strategy);
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
	ft_radix_sort(&a, &b);
	ft_stack_print_top_down(&a);
	ft_stack_print_indices(&a);
	ft_printf("n=%d bits=%d\n", ft_stack_size(&a), ft_count_bits(ft_stack_size(&a)));
	ft_stack_print_top_down(&b);
	ft_cleanup(&a, &b, args, argc == 2);
	return (0);
}
