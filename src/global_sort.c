/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:32:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/26 18:32:21 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

int		find_place_in_a(int *stack, int len, int elem, char **rot_type)
{
	register int i;
	register int place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_elem(stack, len)] || elem < stack[find_min_elem(stack, len)])
		place = find_min_elem(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) ||
			(i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_rot_type(len, place, rot_type));
}

static void	insert_back_in_a(t_stack *stack)
{
	register int	num_of_rots;
	char			*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (stack->b_size)
	{
		num_of_rots = find_place_in_a(stack->stack_a,
			stack->a_size, stack->stack_b[0], &rot_type);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			num_of_rots--;
		}
		apply_pa(stack);
	}
	place_smallest_first_a(stack);
	free(rot_type);
}

static void	insert_leftover_to_b(t_stack *stack)
{
	int idx;

	idx = 0;
	while (stack->a_size > 2)
	{
		idx = find_min_elem(stack->stack_a, stack->a_size);
		if (idx == 0)
			apply_pb(stack);
		else if (idx <= stack->a_size / 2)
			apply_ra(stack);
		else if (idx > stack->a_size / 2)
			apply_rra(stack);
	}
}

static void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rot_type, "ra"))
			apply_ra(stack);
		else
			apply_rra(stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rot_type, "rb"))
			apply_rb(stack);
		else
			apply_rrb(stack);
		best_move->b_moves--;
	}
}

void		global_sort(t_stack *a, t_stack *b)
{
	t_moves		best_move;
	int			optimizer;

	ft_bzero(&best_move, sizeof(best_move));
	optimizer = (a->size > 200 ? 50 : 2);
	while (b->size != 2)
		push(b, a, false, 'b');
	while (a->size > optimizer)
	{
		best_way_from_a_to_b(a, b, &best_move);
		while (best_move.common_moves > 0)
		{
			if (best_move->common_op = OP_RR)
				rotate(a, b, false);
			else
				reverse_rotate(a, b, false);
			--(best_move->common_moves);
		}
		process_moves(a, b, &best_move);
		push(b, a, false);
	}
	insert_leftover_to_b(a, b);
	insert_back_in_a(a, b);
}
