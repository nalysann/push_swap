/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:14:15 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:14:16 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

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

void	swap(t_stack *first, t_stack *second, bool silent_mode);
void	push(t_stack *first, t_stack *second, bool silent_mode, char to);
void	rotate(t_stack *first, t_stack *second, bool silent_mode);
void	reverse_rotate(t_stack *first, t_stack *second, bool silent_mode);

#endif
