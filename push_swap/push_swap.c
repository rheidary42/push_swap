/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:23:23 by rheidary          #+#    #+#             */
/*   Updated: 2025/08/27 15:59:16 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_swap(int *list, int count)
{
	t_node	**structs;
	t_node	*stack_a;
	t_node	*stack_b;
	
	structs = init_structs(list, count);
	if (structs == NULL)
		return (MALLOC_FAILED);
	stack_a = structs[0];
	stack_b = structs[1];
	//Temp Struct init test
	for (int i = 0; i < count; i++)
	{
		printf("Num: %d\n", structs[0][i].num);
		printf("Pos:%d\n", structs[0][i].pos);
		printf("Exp pos:%d\n\n", structs[0][i].exp_pos);
	}
	//sort(structs, count);
	//3 lines to free all the structs;
	//if index + 1 != exp_pos as final check, error message if failed
	return 0;
}

// main really messy, parsing to valid string should be own function.
int	main(int argc, char *argv[])
{
	int	*parsed_list;
	int count;

	count = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');// Free this
		if (argv == NULL)
			return (MALLOC_FAILED);
		count = 0;
		while (argv[count])
			count++;
		parsed_list = parse_input(count++, argv);
	}
	else
		parsed_list = parse_input(count - 1, argv + 1);
	if (parsed_list == NULL && count == argc - 1)
		return (free (argv[1]), write(2, "Error\n", 6), MALLOC_FAILED);
	else if (parsed_list == NULL)
		return (write(2, "Error\n", 6), MALLOC_FAILED);
	push_swap(parsed_list, --count);
	return (0);
	}
