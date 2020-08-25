/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:31:35 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 14:31:36 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "stack.h"

#include <stdbool.h>
#include <stddef.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*a_node;
	t_node	*b_node;
	size_t	size;

	a_node = a->front;
	b_node = b->front;
	size = (a->size > b->size ? a->size : b->size);
	while (size-- > 0)
		if (a->size > size && b->size > size)
		{
			ft_printf("|%11d|    |%11d|\n", a_node->value, b_node->value);
			a_node = a_node->next;
			b_node = b_node->next;
		}
		else if (a->size > size)
		{
			ft_printf("|%11d|    |%11s|\n", a_node->value, "");
			a_node = a_node->next;
		}
		else if (b->size > size)
		{
			ft_printf("|%11s|    |%11d|\n", "", b_node->value);
			b_node = b_node->next;
		}

	ft_printf("--->  a  <---****--->  b  <---\n");
}

bool	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->front;
	while (node != NULL && node->next != NULL)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}
