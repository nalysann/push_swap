/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:31:58 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 14:31:59 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include <stddef.h>

void	push_back(t_stack *stack, t_node *node)
{
	node->prev = stack->back;
	node->next = NULL;
	if (stack->back != NULL)
		stack->back->next = node;
	stack->back = node;
	if (stack->front == NULL)
		stack->front = node;
	++(stack->size);
}

void	push_front(t_stack *stack, t_node *node)
{
	node->prev = NULL;
	node->next = stack->front;
	if (stack->front != NULL)
		stack->front->prev = node;
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
	else if (stack->front->next == stack->back)
		stack->front->next = NULL;
	node = stack->back;
	stack->back = node->prev;
	if (stack->back != NULL)
		stack->back->next = NULL;
	--(stack->size);
	return (node);
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*node;

	if (stack->back == stack->front)
		stack->back = NULL;
	else if (stack->back->prev == stack->front)
		stack->back->prev = NULL;
	node = stack->front;
	stack->front = node->next;
	if (stack->front != NULL)
		stack->front->prev = NULL;
	--(stack->size);
	return (node);
}
