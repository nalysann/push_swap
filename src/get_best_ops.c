/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:14:36 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 15:14:37 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque.h"
#include "operations.h"

#include "ft_string.h"

#include <stddef.h>

static int		get_place_in_b(t_deque *deque, size_t len, int value, t_op_code *op)
{
	size_t		i;
	int		place;

	i = 0;
	place = 0;
	if (len == 2 && value > deque->values[0] && value < deque->values[1])
		place = 0;
	else if (len == 2 && value < deque->values[0] && value > deque->values[1])
		place = 1;
	else if (value > get_max_value(deque) || value < get_min_value(deque))
		place = get_max_index(deque);
	else
		while (i < len)
		{
			if (value < deque->values[i] && ((i + 1 < len && value > deque->values[i + 1]) ||
									(i + 1 == len && value > deque->values[0])))
			{
				place = i + 1;
				break ;
			}
			++i;
		}
	return (get_b_rot_type(len, place, op));
}

static int		get_simultaneous(t_ops *ops)
{
	int		common;

	common = 0;
	if ((ops->a_op == OP_RRA && ops->b_op == OP_RRB) ||
		(ops->a_op == OP_RA && ops->b_op == OP_RB))
	{
		common = (ops->a_amount > ops->b_amount ? ops->b_amount : ops->a_amount);
		if (common > 0)
		{
			ops->s_op = (ops->a_op == OP_RA ? OP_RR : OP_RRR);
			ops->b_amount -= common;
			ops->a_amount -= common;
		}
	}
	return (common);
}

static void		ger_current_ops(t_deque *a, t_deque *b, int pos, t_ops *current)
{
	current->value = a->values[pos];
	current->a_amount = get_a_rot_type(a->size, pos, &(current->a_op));
	current->b_amount = get_place_in_b(b, b->size, a->values[pos], &(current->b_op));
	current->s_amount = get_simultaneous(current);
	current->total_amount = current->a_amount + current->b_amount + current->s_amount;
}

void			get_best_ops(t_deque *a, t_deque *b, t_ops *best)
{
	t_ops	current;
	size_t	i;

	ft_bzero(&current, sizeof(current));
	i = 0;
	while (i < a->size)
	{
		ger_current_ops(a, b, i, &current);
		if (i == 0 || current.total_amount < best->total_amount)
			*best = current;
		++i;
	}
}
