/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:46:15 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 11:46:17 by nalysann         ###   ########.fr       */
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

int				find_place_in_a(t_deque *deque, size_t len, int elem, t_op_code *op);
void			move_back(t_deque *a, t_deque *b);
void			move_after_margin(t_deque *a, t_deque *b);
void			process_ops(t_deque *a, t_deque *b, t_ops *ops);

int				get_a_rot_type(int len, int pos, t_op_code *op);
int				get_b_rot_type(int len, int pos, t_op_code *op);

#endif
