/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:14:05 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:14:07 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int		tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->front->value;
	stack->front->value = stack->front->prev->value;
	stack->front->prev->value = tmp;
}

void	push(t_stack *first, t_stack *second)
{
	if (second->size == 0)
		return ;
	push_front(first, pop_front(second));
}

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	push_back(stack, pop_front(stack));
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	push_front(stack, pop_back(stack));
}
