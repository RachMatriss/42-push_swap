/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:54:26 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 10:06:24 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * ft_is_solved func
 */
int	ft_is_solved(t_node *stack)
{
	t_node	*head;

	if (!stack)
		return (0);
	if (stack->content > stack->prev->content)
		return (0);
	head = stack;
	while (stack->next != head)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
 * ft_stack_size() func
 */
int	ft_stack_size(t_node *stack)
{
	t_node	*head;
	int		i;

	if (!stack)
		return (0);
	i = 1;
	head = stack;
	while (stack->next != head)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/*
 * Max stack func
 */
int	ft_max_in_stack(t_node *stack)
{
	t_node	*head;
	int		max;

	if (!stack)
		return (0);
	max = stack->prev->content;
	head = stack;
	while (stack->next != head)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

/*
 * Min stack func
 */
int	ft_min_in_stack(t_node *stack)
{
	t_node	*head;
	int		min;

	if (!stack)
		return (0);
	min = stack->prev->content;
	head = stack;
	while (stack->next != head)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

/*
 * print stack func
 */
void	ft_print_stack(t_node *stack)
{
	t_node	*head;

	head = stack;
	if (!stack)
	{
		ft_printf("stack empty!\n");
		return ;
	}
	if (stack == stack->next)
	{
		ft_printf("%d\n", stack->content);
		return ;
	}
	while (stack->next != head)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
	ft_printf("%d\n", stack->content);
}
