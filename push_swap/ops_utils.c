/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:59:04 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/14 08:53:40 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_space(t_node *stack, int count)
{
	while (stack[count - 1].pos == -1)
		count--;
	while (count >= 0)
	{
		stack[count + 1] = stack[count];
		count--;
	}
}

void	close_gap(t_node *stack, int count)
{
	int	i;

	if (stack[0].pos == -1)
		return;	
	i = 0;
	while (i < count - 1)
	{
		stack[i] = stack [i + 1];
		i++;
	}
	stack[count - 1].pos = -1;
}