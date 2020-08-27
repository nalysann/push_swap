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

#include "ft_stdio.h"

#include <stdbool.h>
#include <stddef.h>

void	swap(t_stack *first, t_stack *second, bool silent_mode)
{
	int		tmp;

	if (first != NULL && first->size > 1)
	{
		tmp = first->front->value;
		first->front->value = first->front->next->value;
		first->front->next->value = tmp;
	}
	if (second != NULL && second->size > 1)
	{
		tmp = second->front->value;
		second->front->value = second->front->next->value;
		second->front->next->value = tmp;
	}
	if (!silent_mode)
	{
		if (first != NULL && second != NULL)
			ft_printf("ss\n");
		else if (first != NULL)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	push(t_stack *first, t_stack *second, bool silent_mode, char to)
{
	if (second->size > 0)
		push_front(first, pop_front(second));
	if (!silent_mode)
	{
		if (to == 'a')
			ft_printf("pa\n");
		else
			ft_printf("pb\n");
	}
}

void	rotate(t_stack *first, t_stack *second, bool silent_mode)
{
	if (first != NULL && first->size > 1)
		push_back(first, pop_front(first));
	if (second != NULL && second->size > 1)
		push_back(second, pop_front(second));
	if (!silent_mode)
	{
		if (first != NULL && second != NULL)
			ft_printf("rr\n");
		else if (first != NULL)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	reverse_rotate(t_stack *first, t_stack *second, bool silent_mode)
{
	if (first != NULL && first->size > 1)
		push_front(first, pop_back(first));
	if (second != NULL && second->size > 1)
		push_front(second, pop_back(second));
	if (!silent_mode)
	{
		if (first != NULL && second != NULL)
			ft_printf("rrr\n");
		else if (first != NULL)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}
