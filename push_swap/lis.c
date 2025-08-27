/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:25:38 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/27 17:18:19 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_lis(t_node *structs, int **final_lis, int *prev, int bestlen, int bestidx)
{
	int	*lis;

	lis = malloc(sizeof(int) * bestlen);
	if (!lis)
		return;
	while (bestidx >= 0)
	{
		lis[--bestlen] = structs[bestidx].num;
		bestidx = prev[bestidx];
	}
	*final_lis = lis;
}

int	best_lis(t_node *structs, int **final_lis, int *lis, int *prev, int count)
{
	int	bestlen;
	int bestidx;
	int	i;

	bestlen = 0;
	bestidx = 0;
	i = -1;
	while (++i < count)
	{
		if (lis[i] > bestlen)
		{
			bestlen = lis[i];
			bestidx = i;
		}
	}
	make_lis(structs, final_lis, prev, bestlen, bestidx);
	return (bestlen);
}

int	get_lis(t_node *structs, int count, int **final_lis)
{
	int	*lis;
	int	*prev;
	int	i;
	int	j;
	int	longest_lis;

	(lis = malloc (sizeof(int) * count), prev = malloc (sizeof(int) * count));
	if (!lis || !prev)
		return (free (lis), free (prev), 0);
	i = -1;
	while (++i < count)
		(lis[i] = 1, prev[i] = -1);
	i = 0;
	while (++i < count)
	{
		j = -1;
		while (++j < i)
		{
			if (structs[j].num < structs[i].num && lis[j] + 1 > lis[i])
				(lis[i] = lis[j] + 1, prev[i] = j);
		}
	}
	longest_lis = best_lis(structs, final_lis, lis, prev, count);
	return (free (lis), free (prev), longest_lis);
}
