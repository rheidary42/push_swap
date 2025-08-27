/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:40:00 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/27 20:50:17 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	dup_check(int *sorted_list, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (sorted_list[i] == sorted_list[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_satoi(char *nptr, int *sorted_list)
{
	long		store;
	int			sign;
	int			i;

	store = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr [i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != 0 && nptr[i] >= '0' && nptr[i] <= '9')
	{
		store = store * 10 + (nptr[i] - '0');
		if ((sign == 1 && store > 2147483647) ||
			(sign == -1 && store > 2147483648))
			return (false);
		i++;
	}
	if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '\0')
		return (false);
	return (*sorted_list = sign * store, true);
}

int	*parse_input(int count, char *args[])
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * count);// Free this (refactor the free)
	if (sorted_list == NULL)
		return (NULL);
	while (i < count)
	{
		if (!ft_satoi(args[i], &sorted_list[i]))
			return (free(sorted_list), NULL);
		i++;
	}
	if (!dup_check(sorted_list, count))
		return (free(sorted_list), NULL);
	return (sorted_list);
}
