/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:46:27 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/27 21:11:01 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// WHENEVER FUNCTION CALLED, PRINT WHAT WAS CALLED OUTSIDE, TO SOLVE DOUBLE OPERATIONS PRINTING THEIR SUB-OPERATIONS
char	*sa(t_node *stack_a)
{
	t_node	buffer;

	buffer = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = buffer;
	return ("sa");
}

char	*sb(t_node *stack_b)
{
	t_node	buffer;

	buffer = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = buffer;
	return ("sb");
}

char	*ss(t_node **stacks)
{
	sa(stacks[0]);
	sb(stacks[1]);
	return ("ss");
}

char	*pa(t_node **stacks)
{
	if (stacks[0][0].pos != -1)
		make_space(stacks[1]);
	stacks[0][0] = stacks[1][0];
	close_gap(stacks[1]);
	return ("pa");
}

char	*pb(t_node **stacks)
{
	if (stacks[1][0].pos != -1)
		make_space(stacks[1]);
	stacks[1][0] = stacks[0][0];
	close_gap(stacks[0]);
	return ("pb");
}
