/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:42:22 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 19:42:23 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "deque.h"
# include "operations.h"

typedef struct	s_ops
{
	int			value;
	t_op_code	a_op;
	size_t		a_amount;
	t_op_code	b_op;
	size_t		b_amount;
	t_op_code	s_op;
	size_t		s_amount;
	size_t		total_amount;
}				t_ops;

void			get_best_ops(t_deque *a, t_deque *b, t_ops *best);

void			move_back(t_deque *a, t_deque *b);
void			move_after_margin(t_deque *a, t_deque *b);

size_t			get_op(size_t len, size_t pos, t_op_code *op, char name);
size_t			get_insert_position(t_deque *deque, int value, t_op_code *op,
										char name);
void			handle_ops(t_deque *a, t_deque *b, t_ops *ops);

#endif
