/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:27:48 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 10:00:38 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_checker.h"

/*
 * is_valid_instruction() func
 */
static int	is_valid_instruction(char *in)
{
	char	**set;
	int		ret;
	int		i;

	if (ft_strlen(in) > 4)
		return (0);
	ret = 0;
	i = 0;
	set = ft_split("sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n \n", ' ');
	while (set[i])
	{
		if (ft_strncmp(in, set[i], ft_strlen(set[i])) == 0)
			ret = 1;
		free(set[i]);
		i++;
	}
	free(set[i]);
	free(set);
	return (ret);
}

/*
 * rotation_tree func
 */
void	rotation_tree(char *in, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	if (ft_strncmp(in, "rra\n", 4) == 0 || ft_strncmp(in, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate(stack_a, 0);
		i++;
	}
	if (ft_strncmp(in, "rrb\n", 4) == 0 || ft_strncmp(in, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate(stack_b, 0);
		i++;
	}
	if (ft_strncmp(in, "ra\n", 3) == 0 || ft_strncmp(in, "rr\n", 3) == 0)
	{
		ft_rotate(stack_a, 0);
		i++;
	}
	if (ft_strncmp(in, "rb\n", 3) == 0 || ft_strncmp(in, "rr\n", 3) == 0)
	{
		ft_rotate(stack_a, 0);
		i++;
	}
	if (i == 0)
		ft_exit(0, 0);
}

/*
 * push_tree func
 */
void	push_tree(char *in, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(in, "pa\n", 3) == 0)
		ft_push(stack_a, stack_b, 0);
	else if (ft_strncmp(in, "pb\n", 3) == 0)
		ft_push(stack_b, stack_a, 0);
	else
		ft_exit(0, 0);
}

/*
 * swap_tree func
 */
void	swap_tree(char *in, t_node *stack_a, t_node *stack_b)
{
	int	i;

	i = 0;
	if (ft_strncmp(in, "sa\n", 3) == 0 || ft_strncmp(in, "ss\n", 3) == 0)
	{
		ft_swap(stack_a, 0);
		i++;
	}
	if (ft_strncmp(in, "sb\n", 3) == 0 || ft_strncmp(in, "ss\n", 3) == 0)
	{
		ft_swap(stack_b, 0);
		i++;
	}
	if (i == 0)
		ft_exit(0, 0);
}

/*
 * run_instructions func
 **/
int	run_instructions(t_node **stack_a, t_node **stack_b)
{
	char	*in;

	if (ft_is_solved(*stack_a) && !*stack_b)
		return (1);
	in = get_next_line(0);
	while (in)
	{
		if (!is_valid_instruction(in))
			return (free(in), 0);
		if (ft_strncmp(in, "r", 1) == 0)
			rotation_tree(in, stack_a, stack_b);
		else if (ft_strncmp(in, "s", 1) == 0)
			swap_tree(in, *stack_a, *stack_b);
		else if (ft_strncmp(in, "p", 1) == 0)
			push_tree(in, stack_a, stack_b);
		else
			break ;
		free(in);
		if (ft_is_solved(*stack_a) && !*stack_b)
			return (1);
		in = get_next_line(0);
	}
	free(in);
	return (0);
}
