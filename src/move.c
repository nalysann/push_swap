/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:41:49 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 19:41:50 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque.h"
#include "operations.h"

#include "ft_string.h"

#include <stddef.h>

static void		align_deque(t_deque *a)
{
	size_t	min_index;

	min_index = get_min_index(a);
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			rotate(a, NULL, false);
			--min_index;
		}
	}
	else if (min_index < a->size)
	{
		while (min_index < a->size)
		{
			reverse_rotate(a, NULL, false);
			++min_index;
		}
	}
}

void			move_back(t_deque *a, t_deque *b)
{
	size_t		num_of_rots;
	t_op_code	op;

	num_of_rots = 0;
	op = OP_NONE;
	while (b->size > 0)
	{
		num_of_rots = get_insert_position(a, b->values[0], &op, 'a');
		while (num_of_rots > 0)
		{
			if (op == OP_RA)
				rotate(a, NULL, false);
			else
				reverse_rotate(a, NULL, false);
			--num_of_rots;
		}
		push(a, b, false, 'a');
	}
	align_deque(a);
}

void			move_after_margin(t_deque *a, t_deque *b)
{
	size_t		min_idx;

	while (a->size > 2)
	{
		min_idx = get_min_index(a);
		if (0 < min_idx && min_idx <= a->size / 2)
		{
			while (min_idx > 0)
			{
				rotate(a, NULL, false);
				--min_idx;
			}
		}
		else if (a->size / 2 < min_idx)
		{
			while (min_idx < a->size)
			{
				reverse_rotate(a, NULL, false);
				++min_idx;
			}
		}
		push(b, a, false, 'b');
	}
}
