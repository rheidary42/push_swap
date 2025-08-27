#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/libftprintf.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h> // remove

#define MALLOC_FAILED -1

typedef struct	s_node
{
	int	num;
	int	pos;
	int	exp_pos;
}	t_node;

//init.c
t_node	*bubble_sort(t_node *s_buffer, int count);
t_node	*make_buffer(t_node *stack_a, int count);
t_node	*init_exp_pos(t_node **structs, int count);
t_node	*init_b(t_node *stack_b, int count);
t_node	**init_structs(int *list, int count);

//ops.c


//lis.c
int		get_lis(t_node *structs, int count, int **final_lis);
int		best_lis(t_node *structs, int **final_lis, int *lis, int *prev, int count);
void	make_lis(t_node *structs, int **final_lis, int *prev, int bestlen, int bestidx);

//input_parsing.c
bool	dup_check(int *sorted_list, int count);
bool	ft_satoi(char *nptr, int *sorted_list);
int		*parse_input(int count, char *args[]);

//cheapest_push_utils.c
int		ft_abs(int num);
int		stack_size(t_node *stack, int count);
int		rots_to_pop(int idx, int size);
int		calc_cost(int rot_a, int rot_b);

#endif