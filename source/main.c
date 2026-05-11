/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:02:02 by marvin            #+#    #+#             */
/*   Updated: 2026/04/15 15:57:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_parse_flags(int argc, char **argv,
				t_strategy *strategy, int *bench)
{
	int	i;

	i = 1;
	while (i < argc && ft_flag(argv[i]))
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			*bench = 1;
		else
			*strategy = ft_get_strategy(argv[i]);
		i++;
	}
}

int	ft_handle_error(char **args, int is_split)
{
	ft_putstr_fd("Error\n", 2);
	if (is_split)
		ft_free_split(args);
	return (1);
}

void	ft_sort(t_stack *a, t_stack *b, t_strategy strategy, t_bench *bench)
{
	if (ft_is_sorted(a))
		return ;
	if (strategy == COMPLEX)
		ft_radix_sort(a, b, bench);
	else if (strategy == SIMPLE)
		ft_selection_sort(a, b, bench);
	else if (strategy == MEDIUM)
		ft_chunk_sort(a, b, bench);
	else
		ft_adaptive_sort(a, b, bench);
}

void	ft_run(t_stack *a, t_stack *b, t_strategy strategy, int do_bench)
{
	t_bench	bench;
	double	disorder;

	ft_bzero(&bench, sizeof(t_bench));
	disorder = 0.0;
	if (do_bench)
		disorder = ft_compute_disorder(a);
	ft_sort(a, b, strategy, &bench);
	if (do_bench)
		ft_print_bench(&bench, strategy, disorder);
}

int	main(int argc, char **argv)
{
	char		**args;
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			bench;

	bench = 0;
	strategy = ADAPTIVE;
	if (argc < 2)
		return (0);
	if (ft_flag(argv[1]) && argc == 2)
		return (0);
	ft_parse_flags(argc, argv, &strategy, &bench);
	args = ft_get_args(argc, argv);
	if (!args || !ft_valid_input(args))
		return (ft_handle_error(args, argc == 2));
	ft_init_stacks(&a, &b, args);
	ft_run(&a, &b, strategy, bench);
	ft_cleanup(&a, &b, args, argc == 2);
	return (0);
}
