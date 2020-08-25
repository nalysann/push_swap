/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:13:55 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:13:56 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include <stddef.h>

void	push_back(t_stack *stack, t_node *node)
{
	node->prev = NULL;
	node->next = stack->back;
	if (stack->back != NULL)
		stack->back->prev = node;
	stack->back = node;
	if (stack->front == NULL)
		stack->front = node;
	++(stack->size);
}

void	push_front(t_stack *stack, t_node *node)
{
	node->prev = stack->front;
	node->next = NULL;
	if (stack->front != NULL)
		stack->front->next = node;
	stack->front = node;
	if (stack->back == NULL)
		stack->back = node;
	++(stack->size);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*node;

	if (stack->front == stack->back)
		stack->front = NULL;
	else if (stack->front->prev == stack->back)
		stack->front->prev = NULL;
	node = stack->back;
	stack->back = node->next;
	if (stack->back != NULL)
		stack->back->prev = NULL;
	--(stack->size);
	return (node);
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*node;

	if (stack->back == stack->front)
		stack->back = NULL;
	else if (stack->back->next == stack->front)
		stack->back->next = NULL;
	node = stack->front;
	stack->front = node->prev;
	if (stack->front != NULL)
		stack->front->next = NULL;
	--(stack->size);
	return (node);
}
