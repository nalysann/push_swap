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

#include "algorithm.h"
#include "operations.h"
#include "stack.h"

#include "ft_string.h"

#include <limits.h>
#include <stddef.h>

static void	find_place_in_a(t_stack *a, int elem, t_moves *moves)
{
	size_t	i;
	size_t	place;

	i = 0;
	place = 0;
	if (a->size == 2 && a->front->value < elem && elem < a->back->value)
		place = 1;
	else if (a->size == 2 && a->back->value < elem && elem < a->front->value)
		place = 0;
	else if (elem > find_max_elem(a) || elem < find_min_elem(a))
		place = find_min_index(a);
	else
		while (i < a->size)
		{
			if (elem > get_value(a, i) && ((i + 1 < a->size && elem < get_value(a, i + 1)) || (i + 1 == a->size && elem < a->front->value)))
			{
				place = i + 1;
				break ;
			}
			++i;
		}
	find_rot_type(a->size, place, 'a', moves);
}

static void	insert_back_in_a(t_stack *a, t_stack *b)
{
	t_moves		moves;

	while (b->size > 0)
	{
		find_place_in_a(a, b->front->value, &moves);
		while (moves.a_moves > 0)
		{
			if (moves.a_op == OP_RA)
				rotate(a, NULL, false);
			else
				reverse_rotate(a, NULL, false);
			--(moves.a_moves);
		}
		push(a, b, false, 'a');
	}
	place_smallest_first_a(a);
}

static void	insert_leftover_to_b(t_stack *a, t_stack *b)
{
	size_t		idx;

	idx = 0;
	while (a->size > 2)
	{
		idx = find_min_index(a);
		if (idx == 0)
			push(b, a, false, 'b');
		else if (idx <= a->size / 2 || idx == SIZE_T_MAX)
			rotate(a, NULL, false);
		else if (idx > a->size / 2)
			reverse_rotate(a, NULL, false);
	}
}

static void	process_moves(t_stack *a, t_stack *b, t_moves *best_moves)
{
	while (best_moves->common_moves > 0)
	{
		if (best_moves->common_op == OP_RR)
			rotate(a, b, false);
		else
			reverse_rotate(a, b, false);
		--(best_moves->common_moves);
	}
	while (best_moves->a_moves > 0)
	{
		if (best_moves->a_op == OP_RA)
			rotate(a, NULL, false);
		else
			reverse_rotate(a, NULL, false);
		--(best_moves->a_moves);
	}
	while (best_moves->b_moves > 0)
	{
		if (best_moves->b_op == OP_RB)
			rotate(NULL, b, false);
		else
			reverse_rotate(NULL, b, false);
		--(best_moves->b_moves);
	}
}

void		global_sort(t_stack *a, t_stack *b)
{
	t_moves		best_moves;
	size_t		optimizer;

	ft_bzero(&best_moves, sizeof(best_moves));
	optimizer = (a->size > 200 ? 50 : 2);
	while (b->size != 2)
		push(b, a, false, 'b');
	while (a->size > optimizer)
	{
		best_way_from_a_to_b(a, b, &best_moves);
		process_moves(a, b, &best_moves);
		push(b, a, false, 'b');
	}
	insert_leftover_to_b(a, b);
	insert_back_in_a(a, b);
}
