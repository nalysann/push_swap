/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:42:06 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 19:42:07 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "operations.h"

#include <stdbool.h>

size_t			get_op(size_t len, size_t pos, t_op_code *op, char name)
{
	if (pos > len / 2)
	{
		*op = (name == 'a' ? OP_RRA : OP_RRB);
		if (len > 2)
			pos = len - pos;
	}
	else
		*op = (name == 'a' ? OP_RA : OP_RB);
	return (pos);
}

static bool		can_insert(t_deque *deque, int value, size_t pos, char name)
{
	if (name == 'a')
	{
		if (value > deque->values[pos] &&
			((pos + 1 < deque->size && value < deque->values[pos + 1]) ||
			(pos + 1 == deque->size && value < deque->values[0])))
			return (true);
	}
	else
	{
		if (value < deque->values[pos] &&
			((pos + 1 < deque->size && value > deque->values[pos + 1]) ||
			(pos + 1 == deque->size && value > deque->values[0])))
			return (true);
	}
	return (false);
}

size_t			get_insert_position(t_deque *deque, int value, t_op_code *op,
										char name)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	if (deque->size == 2 &&
			value > deque->values[0] && value < deque->values[1])
		pos = (name == 'a' ? 1 : 0);
	else if (deque->size == 2 &&
				value < deque->values[0] && value > deque->values[1])
		pos = (name == 'a' ? 0 : 1);
	else if (value > get_max_value(deque) || value < get_min_value(deque))
		pos = (name == 'a' ? get_min_index(deque) : get_max_index(deque));
	else
		while (i < deque->size)
		{
			if (can_insert(deque, value, i, name))
			{
				pos = i + 1;
				break ;
			}
			++i;
		}
	return (get_op(deque->size, pos, op, name));
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
