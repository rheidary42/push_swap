/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:12:24 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/27 17:11:46 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//While pushing out stack a, potentially double rotate stack b, to optimize insertions into better starting positions.
void	fix_a(t_node **structs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (structs[0][i].exp_pos == 1);
			break;
		i++;
	}
	if (i <= count / 2)
	{
		while (structs[0][0].exp_pos != 1)
			ft_printf("%s", rra(structs[0], count));
	}
	else
	{
		while (structs[0][0].exp_pos != 1)
			ft_printf("%s", ra(structs[0], count));
	}
}

void	push_outcasts(t_node **structs, int *lis, int lislen, int count)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i++ != count)
	{
		if (j + 1 != lislen && structs[0][0].num == lis[j])
		{
			ft_printf("%s", ra(structs[0], count));
			j++;
		}
		else
			ft_printf("%s", pb(structs[0], count));
	}
}

void	sort(t_node **structs, int count)
{
	int	*lis;
	int	lis_size;

	if (count > 5)
	{
		lis_size = get_lis(structs[0], &lis, count);
		if (!lis)
			return;
		push_outcasts(structs, lis, lis_size, count);
		while (structs[1][0].pos != -1)
			pp_cheapest(structs, count);
		fix_a(structs, count);
		free (lis);
	}
	else if (count <= 5 && count > 1)
		small_sort();
}