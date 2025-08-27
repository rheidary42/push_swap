/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_push copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/26 18:40:08 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_smol(t_node *stack, int sizea)
{
	int	i;
	int	idx;

	idx = 0;
	i = 0;
	while (++i < sizea)
	{
		if (stack[i].exp_pos < stack[idx].exp_pos)
			idx = i;
	}
	return (idx);
}

int	find_target(t_node **stacks, int idx, int sizea)
{
	int	i;
	int	b_exp;
	int	next;

	b_exp = stacks[1][idx].exp_pos;
	i = 0;
	while (i < sizea)
	{
		next = (i + 1) % sizea;
		if (stacks[0][i].exp_pos < b_exp && b_exp < stacks[0][next].exp_pos)
			return (next);
		i++;
	}
	return (find_smol(stacks[0], sizea));
}

int	calc_cheapest(t_node **stacks, int count)
{
	ssize_t	i;
	size_t	cost;
	size_t	sizea;
	size_t	sizeb;
	size_t	cheapest[2];

	sizea = stack_size(stacks[0], count);
	sizeb = stack_size(stacks[1], count);
	cheapest[0] = ULONG_MAX;
	i = -1;
	while (++i < sizeb)
	{
		cost = calc_cost(
				rots_to_pop(find_target(stacks, i, sizea), sizea),
				rots_to_pop(i, sizeb)
				);
		if (cost < cheapest[0])
		{
			cheapest[0] = cost;
			cheapest[1] = i;
		}
	}
	return (cheapest[1]);
}

void	pop_cheapest(t_node **stacks, int rot_a, int rot_b, int count)
{
	while (rot_a > 0 && rot_b > 0)
		(ft_printf("%s", rr(stacks, count, 0)), rot_a--, rot_b--);
	while (rot_a < 0 && rot_b < 0)
		(ft_printf("%s", rr(stacks, count, 1)), rot_a++, rot_b++);
	while (rot_a > 0)
		(ft_printf("%s", ra(stacks, count)), rot_a--);
	while (rot_a < 0)
		(ft_printf("%s", rra(stacks, count)), rot_a++);
	while (rot_b > 0)
		(ft_printf("%s", rb(stacks, count)), rot_b--);
	while (rot_b < 0 && rot_b)
		(ft_printf("%s", rrb(stacks, count)), rot_b--);
}

void	pp_cheapest(t_node **stacks, int count)
{
	int	cheapest_idx;
	int	sizea;
	int	sizeb;
	int	rot_a;
	int	rot_b;

	sizea = stack_size(stacks[0], count);
	sizeb = stack_size(stacks[1], count);
	cheapest_idx = calc_cheapest(stacks, count);
	rot_a = rots_to_pop(find_target(stacks, cheapest_idx, sizea), sizea);
	rot_b = rots_to_pop(cheapestIdx, sizeb);
	pop_cheapest();
	ft_printf("%s", pa(stacks, count));
}
