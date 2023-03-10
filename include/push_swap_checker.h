/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:17:07 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 10:13:15 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "push_swap.h"

void	push_tree(char *in, t_node **stack_a, t_node **stack_b);
void	swap_tree(char *in, t_node *stack_a, t_node *stack_b);
void	rotation_tree(char *in, t_node **stack_a, t_node **stack_b);
int		run_instructions(t_node **stack_a, t_node **stack_b);

#endif
