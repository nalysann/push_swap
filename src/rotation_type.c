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

#include "operations.h"

int		get_a_rot_type(int len, int pos, t_op_code *op)
{
	if (pos > len / 2)
	{
		*op = OP_RRA;
		if (len > 2)
			pos = len - pos;
	}
	else
		*op = OP_RA;
	return (pos);
}

int		get_b_rot_type(int len, int pos, t_op_code *op)
{
	if (pos > len / 2)
	{
		*op = OP_RRB;
		if (len > 2)
			pos = len - pos;
	}
	else
		*op = OP_RB;
	return (pos);
}

