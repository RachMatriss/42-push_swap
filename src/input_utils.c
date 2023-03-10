/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:25:00 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/01 11:07:02 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * input check_dup func
 */
int	check_dup(ssize_t *lst, int len)
{
	int	i;
	int	j;

	if (!lst)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (lst[i] == lst[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * input error_handler func
 * var INT_MAX - MIN => INT32_MAX && INT32_MIN in MacOs
 *  2147483647  <= INT_MAX value
 * -2147483647 <= INT_MIN value
 */
void	error_handler(int argc, char const **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
			ft_exit(0, 0);
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) \
				&& argv[i][j] != '-' \
				&& argv[i][j] != '+')
				ft_exit(0, 0);
			j++;
		}
		i++;
	}
}

/*
 * bubble_sort func
 */
static void	bubble_sort(ssize_t *list, int len)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (list[j] > list[j + 1])
			{
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
 * allocate_and_fill func
 */
int	allocate_and_fill(ssize_t **ret, ssize_t **srt, char const **list, int len)
{
	int	i;

	*ret = (ssize_t *)malloc(len * sizeof(ssize_t));
	*srt = (ssize_t *)malloc(len * sizeof(ssize_t));
	if (!(*ret) || !(*srt))
	{
		ft_free(*ret);
		ft_free(*srt);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		(*ret)[i] = ft_atoi(list[i]);
		(*srt)[i] = ft_atoi(list[i]);
		i++;
	}
	bubble_sort(*srt, len);
	return (1);
}

/*
 * format_input func
 */
ssize_t	*format_input(int len, char const **list)
{
	ssize_t	*ret;
	ssize_t	*srt;
	int		i;
	int		j;

	if (!allocate_and_fill(&ret, &srt, list, len))
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ret[i] == srt[j])
			{
				ret[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_free(srt);
	return (ret);
}
