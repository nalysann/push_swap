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

#include "algorithm.h"
#include "operations.h"
#include "stack.h"

#include "ft_math.h"
#include "ft_string.h"

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
	else if (moves->elem > find_max_elem(b) ||
			moves->elem < find_min_elem(b))
		place = find_max_index(b);
	else
		while (i < b->size)
		{
			if (moves->elem < get_value(b, i) && ((i + 1 < b->size && moves->elem > get_value(b, i + 1)) ||
			(i + 1 == b->size && moves->elem > b->front->value)))
			{
				place = i + 1;
				break ;
			}
			++i;
		}
	find_rot_type(b->size, place, 'b', moves);
}

static void		calc_moves_from_a_to_b(t_stack *a, t_stack *b, size_t pos, t_moves *moves)
{
	moves->elem = get_value(a, pos);
	find_rot_type(a->size, pos, 'a', moves);
	find_place_in_b(b, moves);
	find_common(moves);
	moves->total_moves = moves->a_moves + moves->b_moves + moves->common_moves + 1;
}

void			best_way_from_a_to_b(t_stack *a, t_stack *b, t_moves *best_moves)
{
	t_moves		moves;
	size_t		i;

	ft_bzero(&moves, sizeof(moves));
	i = 0;
	while (i < a->size)
	{
		calc_moves_from_a_to_b(a, b, i, &moves);
		if (i == 0 || best_moves->total_moves > moves.total_moves)
			*best_moves = moves;
		++i;
	}
}
