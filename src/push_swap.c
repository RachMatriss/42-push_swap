/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:34:04 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 10:09:04 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * perform radix sort
 */
static void	radix(t_node *stack_a, t_node *stack_b)
{
	int	i;
	int	j;
	int	bits;
	int	size;

	size = ft_stack_size(stack_a);
	bits = 0;
	while (size >> bits != 0)
		bits++;
	i = -1;
	while (++i < bits)
	{
		if (ft_is_solved(stack_a))
			return ;
		j = -1;
		while (++j < size)
		{
			if ((stack_a->content >> i & 1) == 1)
				ft_rotate(&stack_a, 'a');
			else
				ft_push(&stack_b, &stack_a, 'b');
		}
		while (stack_b)
			ft_push(&stack_a, &stack_b, 'a');
	}
}

/*
 * sort three func
 */
static void	sort_three(t_node **stack_a, char c)
{
	if ((*stack_a)->content == ft_min_in_stack(*stack_a))
	{
		if ((*stack_a)->next->content < (*stack_a)->prev->content)
			return ;
		ft_reverse_rotate(stack_a, c);
		ft_swap(*stack_a, c);
	}
	else if ((*stack_a)->content < ft_max_in_stack(*stack_a) \
			&& (*stack_a)->content > ft_min_in_stack(*stack_a))
	{
		if ((*stack_a)->next->content == ft_max_in_stack(*stack_a))
			ft_reverse_rotate(stack_a, c);
		else
			ft_swap(*stack_a, c);
	}
	else if ((*stack_a)->content == ft_max_in_stack(*stack_a))
	{
		ft_rotate(stack_a, c);
		if ((*stack_a)->content != ft_min_in_stack(*stack_a))
			ft_swap(*stack_a, c);
	}
}

/*
 * move_smallest func
 **/
static void	move_smallest(t_node **stack_a, t_node **stack_b, int i)
{
	int	size;

	size = ft_stack_size(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->content == 0 || (*stack_a)->content == 1)
		{
			ft_push(stack_b, stack_a, 'b');
			size--;
		}
		else
		{
			if (i < size / 2)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
	}
}

/*
 * sort small func
 */
static void	sort_small(t_node *stack_a, t_node *stack_b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a;
	while (i < ft_stack_size(stack_a))
	{
		if (tmp->content == 0 || tmp->content == 1)
			break ;
		tmp = tmp->next;
		i++;
	}
	move_smallest(&stack_a, &stack_b, i);
	if (stack_b->content == 0)
		ft_swap(stack_b, 'b');
	sort_three(&stack_a, 'a');
	ft_push(&stack_a, &stack_b, 'a');
	ft_push(&stack_a, &stack_b, 'a');
}

/*
 * sort func
 */
void	sort(t_node *stack_a, t_node *stack_b)
{
	if (ft_is_solved(stack_a))
		return ;
	else if (ft_stack_size(stack_a) < 4)
		sort_three(&stack_a, 'a');
	else if (ft_stack_size(stack_a) < 6)
		sort_small(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
