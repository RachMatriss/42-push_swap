/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:22:36 by ramedjra          #+#    #+#             */
/*   Updated: 2023/02/28 19:58:32 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_checker.h"

int	main(int argc, char const *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	ssize_t	*input;
	int		i;

	if (argc < 2)
		exit(0);
	error_handler(argc - 1, &argv[1]);
	input = format_input(argc - 1, &argv[1]);
	if (!check_dup(input, argc - 1))
		ft_exit(0, 0);
	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
	while (i-- > 0)
		add_front(&stack_a, new_node(input[i]));
	free(input);
	i = run_instructions(&stack_a, &stack_b);
	lst_clear(stack_a);
	lst_clear(stack_b);
	if (i)
		ft_exit("OK", 0);
	ft_exit("KO", 0);
}
