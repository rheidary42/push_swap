/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:28:51 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/25 17:20:52 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node	*bubble_sort(t_node *a_buffer, int count)
{
	int		i;
	int		j;
	t_node	buffer;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (a_buffer[j].num > a_buffer[j + 1].num)
			{
				buffer = a_buffer[j];
				a_buffer[j] = a_buffer[j + 1];
				a_buffer[j + 1] = buffer;
			}
		}
	}
	return (a_buffer);
}

t_node	*make_buffer(t_node *stack_a, int count)
{
	int		i;
	t_node	*buffer;

	buffer = malloc(sizeof(t_node) * count);
	if (buffer == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		buffer[i] = stack_a[i];
		buffer[i].pos = i;
	}
	return (buffer);
}

t_node	*init_exp_pos(t_node **structs, int count)
{
	int		i;
	t_node	*a_buffer;

	a_buffer = make_buffer(structs[0], count);
	if (a_buffer == NULL)
		return (NULL);
	a_buffer = bubble_sort(a_buffer, count);
	i = -1;
	while (++i < count)
		structs[0][a_buffer[i].pos].exp_pos = i + 1;
	free (a_buffer);
	return (structs[0]);
}

t_node	*init_b(t_node *stack_b, int count)
{
	int	i;
	
	i = 0;
	while (i <= count)
	{
		stack_b[i].num = -1;
		stack_b[i].pos = -1;
		stack_b[i].exp_pos = -1;
		i++;
	}
	return (stack_b);
}

t_node	**init_structs(int *numbers, int count)
{
	int		i;
	t_node	**structs;

	structs = malloc(sizeof(t_node *) * 2);
	if (structs == NULL)
		return (NULL);
	structs[0] = malloc(sizeof(t_node) * (count + 1));// Free at end
	structs[1] = malloc(sizeof(t_node) * (count + 1));
	if (structs[0] == NULL || structs[1] == NULL)
		return (free(structs[0]), free(structs[1]), free (structs), NULL);
	i = -1;
	while (++i < count)
	{
		structs[0][i].num = numbers[i];
		structs[0][i].pos = i + 1;
	}
	structs[0] = init_exp_pos(structs, count);
	if (structs[0] == NULL)
		return (free(structs[0]), free (structs[1]), free (structs), NULL);
	structs[1] = init_b(structs[1], count);
	return (free(numbers), structs);
}
