/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:12:22 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 10:02:09 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * ft_swap() func
 **/
void	ft_swap(t_node *stack, char c)
{
	ssize_t	tmp;

	if (stack == stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	if (c != 0)
		ft_printf("s%c\n", c);
}

/*
 * ft_push() func
 **/
void	ft_push(t_node **stack_one, t_node **stack_two, char c)
{
	if (!(*stack_two))
		return ;
	add_front(stack_one, pop_front(stack_two));
	if (c != 0)
		ft_printf("p%c\n", c);
}

/*
 * ft_rotate() func
 **/
void	ft_rotate(t_node **stack, char c)
{
	if (!(*stack))
		return ;
	*stack = (*stack)->next;
	if (c != 0)
		ft_printf("r%c\n", c);
}

/*
 * ft_reverse_rotate() func
 **/
void	ft_reverse_rotate(t_node **stack, char c)
{
	if (!(*stack))
		return ;
	*stack = (*stack)->prev;
	if (c != 0)
		ft_printf("rr%c\n", c);
}
