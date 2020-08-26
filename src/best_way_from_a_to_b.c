/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_way_from_a_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:39:57 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/26 18:39:58 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "ft_math.h"

#include <stddef.h>

static void		find_common(t_moves *moves)
{
	if ((moves->a_op == OP_RA && moves->b_op == OP_RB) ||
		(moves->a_op == OP_RRA && moves->b_op == OP_RRB))
	{
		moves->common_moves = ft_min(moves->a_moves, moves->b_moves);
		if (moves->common_moves > 0)
		{
			moves->common_op = (moves->a_op == OP_RA ? OP_RR : OP_RRR);
			moves->a_moves -= moves->common_moves;
			moves->b_moves -= moves->common_moves;
		}
	}
}

static void		find_place_in_b(t_stack *b, t_moves *moves)
{
	size_t	i;
	size_t	place;

	i = 0;
	place = 0;
	if (b->size == 2 && moves->elem > b->front->value && moves->elem < b->back->value)
		place = 0;
	else if (b->size == 2 && moves->elem < b->front->value && moves->elem > b->back->value)
		place = 1;
	else if (moves->elem > get_value(b, find_max_elem(b, b->size)) ||
			moves->elem < get_value(b, find_min_elem(b, b->size)))
		place = find_max_elem(b, b->size);
	else
		while (i < b->size)
		{
			if (moves->elem < get_value(b, i) && (i + 1 < b->size && moves->elem > get_value(b, i + 1) ||
			(i + 1 == b->size && moves->elem > b->front->value)))
			{
				place = i + 1;
				break ;
			}
			++i;
		}
	find_rot_type(len, place, 'b', moves);
}

static void		calc_moves_from_a_to_b(t_stack *a, t_stack *b, size_t pos, t_moves *moves)
{
	moves->elem = get_value(a, pos);
	find_rot_type(a->size, pos, 'a', moves);
	find_place_in_b(b, moves);
	find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves + 1;
	return (moves);
}

void			best_way_from_a_to_b(t_stack *a, t_stack *b, t_moves *best_move)
{
	t_moves		moves;
	size_t		i;

	ft_bzero(&moves, sizeof(moves));
	i = 0;
	while (i < a->size)
	{
		calc_moves_from_a_to_b(a, b, i, &moves);
		if (i == 0)
			best_move = moves;
		else if (best_move->total > moves->total)
		{
			free_moves(best_move);
			best_move = moves;
		}
		else
			free_moves(moves);
		++i;
	}
	return (best_move);
}
