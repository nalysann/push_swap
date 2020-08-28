/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:41:41 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 19:41:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque.h"
#include "operations.h"

#include "ft_math.h"
#include "ft_string.h"

#include <stddef.h>

static int		get_simultaneous(t_ops *ops)
{
	int		common;

	common = 0;
	if ((ops->a_op == OP_RRA && ops->b_op == OP_RRB) ||
		(ops->a_op == OP_RA && ops->b_op == OP_RB))
	{
		common = (ops->a_amount > ops->b_amount
					? ops->b_amount
					: ops->a_amount);
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
	current->a_amount = get_op(a->size, pos, &(current->a_op), 'a');
	current->b_amount =
			get_insert_position(b, a->values[pos], &(current->b_op), 'b');
	current->s_amount = get_simultaneous(current);
	current->total_amount =
			current->a_amount + current->b_amount + current->s_amount;
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
