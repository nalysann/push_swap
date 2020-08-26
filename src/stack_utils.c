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

#include "stack.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include <stdbool.h>
#include <stddef.h>

void	initialize_stack(t_stack *stack, int beg, int end, char **argv)
{
	int		i;
	t_node	*node;

	ft_bzero(stack, sizeof(*stack));
	i = beg;
	while (i < end)
	{
		if (!(node = ft_memalloc(sizeof(*node))))
			ft_throw(MEMORY_MSG, E_MEMORY);
		node->value = ft_atoi(argv[i]);
		push_back(stack, node);
		++i;
	}
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

int		get_value(t_stack *stack, size_t pos)
{
	t_node	*node;
	size_t	i;

	node = stack->front;
	i = 0;
	while (i < pos)
		node = node->next;
	return (node->value);
}
