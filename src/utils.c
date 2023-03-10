/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:05:03 by ramedjra          #+#    #+#             */
/*   Updated: 2023/02/28 19:30:54 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_exit(char *msg, void *ptr)
{
	if (ptr)
		free(ptr);
	if (!msg)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		ft_printf("%s\n", msg);
	exit(0);
}
