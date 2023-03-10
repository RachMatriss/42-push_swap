/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:57:47 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 10:16:45 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	ssize_t			content;
}	t_node;

/* instructions.c */
void	ft_swap(t_node *stack, char c);
void	ft_push(t_node **stack_one, t_node **stack_two, char c);
void	ft_rotate(t_node **stack, char c);
void	ft_reverse_rotate(t_node **stack, char c);
/* list_utils.c */
t_node	*new_node(int content);
void	add_front(t_node **lst, t_node *new_node);
t_node	*pop_front(t_node **list);
void	lst_clear(t_node *list);
/* psuh_swap.c */
int		ft_is_solved(t_node *stack);
int		ft_stack_size(t_node *stack);
int		ft_max_in_stack(t_node *stack);
int		ft_min_in_stack(t_node *stack);
void	ft_print_stack(t_node *stack);
void	sort(t_node *stack_a, t_node *stack_b);
/* input file*/
ssize_t	*format_input(int len, char const **list);
void	error_handler(int argc, char const **argv);
int		check_dup(ssize_t *lst, int len);
/* utils.c */
void	ft_free(void *ptr);
void	ft_exit(char *msg, void *ptr);

#endif
