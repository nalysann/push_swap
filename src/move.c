/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:53:31 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 14:53:33 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque.h"
#include "operations.h"

#include "ft_string.h"

#include <stddef.h>

static int		get_insert_position(t_deque *deque, size_t len, int value, t_op_code *op)
{
	size_t		i;
	int		place;

	i = 0;
	place = 0;
	if (len == 2 && value > deque->values[0] && value < deque->values[1])
		place = 1;
	else if (len == 2 && value < deque->values[0] && value > deque->values[1])
		place = 0;
	else if (value > get_max_value(deque) || value < get_min_value(deque))
		place = get_min_index(deque);
	else
		while (i < len)
		{
			if (value > deque->values[i] && ((i + 1 < len && value < deque->values[i + 1]) ||
									(i + 1 == len && value < deque->values[0])))
			{
				place = i + 1;
				break ;
			}
			++i;
		}
	return (get_a_rot_type(len, place, op));
}

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
	int			num_of_rots;
	t_op_code	op;

	num_of_rots = 0;
	op = OP_NONE;
	while (b->size > 0)
	{
		num_of_rots = get_insert_position(a, a->size, b->values[0], &op);
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

void			handle_ops(t_deque *a, t_deque *b, t_ops *ops)
{
	while (ops->s_amount > 0)
	{
		if (ops->s_op == OP_RR)
			rotate(a, b, false);
		else
			reverse_rotate(a, b, false);
		--ops->s_amount;
	}
	while (ops->a_amount > 0)
	{
		if (ops->a_op == OP_RA)
			rotate(a, NULL, false);
		else
			reverse_rotate(a, NULL, false);
		--ops->a_amount;
	}
	while (ops->b_amount > 0)
	{
		if (ops->b_op == OP_RB)
			rotate(NULL, b, false);
		else
			reverse_rotate(NULL, b, false);
		--ops->b_amount;
	}
}
