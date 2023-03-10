/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:06:14 by ramedjra          #+#    #+#             */
/*   Updated: 2023/02/28 19:48:11 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*new_node(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = new;
	new->prev = new;
	return (new);
}

void	add_front(t_node **list, t_node *new_node)
{
	if (!(*list))
	{
		(*list) = new_node;
		return ;
	}
	(*list)->prev->next = new_node;
	new_node->prev = (*list)->prev;
	new_node->next = *list;
	(*list)->prev = new_node;
	*list = new_node;
}

t_node	*pop_front(t_node **list)
{
	t_node	*tmp;

	if (!(*list))
		return (NULL);
	if ((*list) == (*list)->next)
	{
		tmp = *list;
		*list = NULL;
		return (tmp);
	}
	tmp = *list;
	(*list)->prev->next = (*list)->next;
	(*list)->next->prev = (*list)->prev;
	(*list) = (*list)->next;
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	lst_clear(t_node *list)
{
	t_node	*tmp;

	if (!list)
		return ;
	list->prev->next = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
