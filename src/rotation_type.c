/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:47:03 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/26 18:47:06 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	find_rot_type(size_t size, size_t pos, char stack, t_moves *moves)
{	
	if (pos > size / 2)
	{
		stack == 'a' ? (moves->a_op = OP_RRA) : (moves->b_op = OP_RRB);
		if (size > 2)
			pos = size - pos;
	}
	else
	{
		stack == 'a' ? (moves->a_op = OP_RA) : (moves->b_op = OP_RB);
	}
	stack == 'a' ? (moves->a_moves = pos) : (moves->b_moves = pos);
}
