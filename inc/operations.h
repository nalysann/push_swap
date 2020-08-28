/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:42:38 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 19:42:38 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "deque.h"

# include <stdbool.h>

typedef enum	e_op_code
{
	OP_NONE,
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}				t_op_code;

void	swap(t_deque *first, t_deque *second, bool silent_mode);
void	push(t_deque *first, t_deque *second, bool silent_mode, char to);
void	rotate(t_deque *first, t_deque *second, bool silent_mode);
void	reverse_rotate(t_deque *first, t_deque *second, bool silent_mode);

#endif
