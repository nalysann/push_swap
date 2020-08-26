/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:14:38 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/26 11:14:41 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "operations.h"
# include "stack.h"

typedef struct	s_moves
{
	int			elem;
	int			a_moves;
	t_op_code	a_op;
	int			b_moves;
	t_op_code	b_op;
	int			common_moves;
	t_op_code	common_op;

}				t_moves;

void			find_rot_type(size_t size, size_t pos, char stack, t_moves *moves);

#endif
