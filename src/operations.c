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

#include <stddef.h>

void	swap(t_stack *a, t_stack *b)
{
	int		tmp;

	if (a != NULL && a->size > 1)
	{
		tmp = a->front->value;
		a->front->value = a->front->next->value;
		a->front->next->value = tmp;
	}
	if (b != NULL && b->size > 1)
	{
		tmp = b->front->value;
		b->front->value = b->front->next->value;
		b->front->next->value = tmp;
	}
}

void	push(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		push_front(a, pop_front(b));
}

void	rotate(t_stack *a, t_stack *b)
{
	if (a != NULL && a->size > 1)
		push_back(a, pop_front(a));
	if (b != NULL && b->size > 1)
		push_back(b, pop_front(b));
}

void	reverse_rotate(t_stack *a, t_stack *b)
{
	if (a != NULL && a->size > 1)
		push_front(a, pop_back(a));
	if (b != NULL && b->size > 1)
		push_front(b, pop_back(b));
}
