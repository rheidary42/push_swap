/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_push_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:17:04 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/26 14:20:04 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	stack_size(t_node *stack, int count)
{
	int i;

	i = 0;
	while (i < count && stack[i].pos != -1)
		i++;
	return (i);
}

int	rots_to_pop(int idx, int size)
{
	if (idx <= size / 2)
		return (idx);
	else
		return (idx - size);
}

int	calc_cost(int rot_a, int rot_b)
{
	if ((rot_a >= 0 && rot_b >= 0) || rot_a < 0 && rot_b < 0)
	{
		if (ft_abs(rot_a) > ft_abs(rot_b))
			return (ft_abs(rot_a));
		return (ft_abs(rot_b));
	}
	return (ft_abs(rot_a) + ft_abs(rot_b));
}