/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:19:46 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/22 16:52:56 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

#include <limits.h>
#include <stddef.h>

size_t	find_min_index(t_stack *stack)
{
	int		min;
	size_t	min_idx;
	size_t	i;
	t_node	*node;

	if (stack->size == 0)
		return (-1);
	min = stack->front->value;
	min_idx = 0;
	i = 1;
	node = stack->front->next;
	while (node != NULL)
	{
		if (node->value < min)
		{
			min = node->value;
			min_idx = i;
		}
		++i;
		node = node->next;
	}
	return (min_idx);
}

size_t	find_max_index(t_stack *stack)
{
	int		max;
	size_t	max_idx;
	size_t	i;
	t_node	*node;

	if (stack->size == 0)
		return (-1);
	max = stack->front->value;
	max_idx = 0;
	i = 1;
	node = stack->front->next;
	while (node != NULL)
	{
		if (node->value > max)
		{
			max = node->value;
			max_idx = i;
		}
		++i;
		node = node->next;
	}
	return (max_idx);
}

int		find_min_elem(t_stack *stack)
{
	int		min;
	t_node	*node;

	if (stack->size == 0)
		return (INT_MIN);
	min = stack->front->value;
	node = stack->front->next;
	while (node != NULL)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

int		find_max_elem(t_stack *stack)
{
	int		max;
	t_node	*node;

	if (stack->size == 0)
		return (INT_MAX);
	max = stack->front->value;
	node = stack->front->next;
	while (node != NULL)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

void	place_smallest_first_a(t_stack *a)
{
	size_t	min_index;

	min_index = find_min_index(a);
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			rotate(a, NULL, false);
			--min_index;
		}
	}
	else if (min_index < a->size)
	{
		while (min_index < a->size)
		{
			reverse_rotate(a, NULL, false);
			++min_index;
		}
	}
}
