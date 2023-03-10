/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:49:17 by ramedjra          #+#    #+#             */
/*   Updated: 2023/02/28 19:26:22 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char const **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	ssize_t	*input;
	int		i;

	if (argc < 2)
		exit(1);
	error_handler(argc - 1, &argv[1]);
	input = format_input(argc - 1, &argv[1]);
	if (!check_dup(input, argc - 1))
		ft_exit(0, input);
	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
	while (i-- > 0)
		add_front(&stack_a, new_node(input[i]));
	free(input);
	sort(stack_a, stack_b);
	lst_clear(stack_a);
	lst_clear(stack_b);
	return (0);
}
