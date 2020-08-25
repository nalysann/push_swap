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

void	swap(t_stack *a, t_stack *b);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *a, t_stack *b);

#endif
