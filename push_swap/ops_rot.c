/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:51:30 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/27 21:11:49 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_node *stack_a, int count)
{
	t_node	buffer;
	int		i;

	buffer = stack_a[0];
	i = 0;
	while (stack_a[i + 1].pos != -1 && 	i + 1 < count)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = buffer;
	return ("ra");
}

char	*rb(t_node *stack_b, int count)
{
	t_node	buffer;
	int		i;

	buffer = stack_b[0];
	i = 0;
	while (stack_b[i + 1].pos != -1 && 	i + 1 < count)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = buffer;
	return ("rb");
}

char	*rra(t_node *stack_a, int count)
{
	t_node	buffer;

	count = count - 1;
	while (count >= 0 && stack_a[count].pos != -1)
		count--;
	buffer = stack_a[count];
	while (count > 0)
	{
		stack_a[count] = stack_a[count - 1];
		count--;
	}
	stack_a[count] = buffer;
	return ("rra");
}

char	*rrb(t_node *stack_b, int count)
{
	t_node	buffer;

	count = count - 1;
	while (count >= 0 && stack_b[count].pos != -1)
		count--;
	buffer = stack_b[count];
	while (count > 0)
	{
		stack_b[count] = stack_b[count - 1];
		count--;
	}
	stack_b[count] = buffer;
	return ("rrb");
}

//	booli -> 0 = rr || booli -> 1 == rrr
char	*rr(t_node **stacks, int booli)
{
	
}