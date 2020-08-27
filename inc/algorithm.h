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

# include "operations.h"
# include "stack.h"

typedef struct	s_moves
{
	int			elem;
	size_t		a_moves;
	t_op_code	a_op;
	size_t		b_moves;
	t_op_code	b_op;
	size_t		common_moves;
	t_op_code	common_op;
	size_t		total_moves;

}				t_moves;

void			best_way_from_a_to_b(t_stack *a, t_stack *b, t_moves *best_moves);

void			global_sort(t_stack *a, t_stack *b);

void			find_rot_type(size_t size, size_t pos, char stack, t_moves *moves);

size_t			find_min_index(t_stack *stack);
size_t			find_max_index(t_stack *stack);
int				find_min_elem(t_stack *stack);
int				find_max_elem(t_stack *stack);
void			place_smallest_first_a(t_stack *a);

#endif
