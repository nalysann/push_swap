/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:41:55 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 19:41:55 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

#include "ft_stdio.h"

#include <stdbool.h>
#include <stddef.h>

void	swap(t_deque *first, t_deque *second, bool silent_mode)
{
	int		tmp;

	if (first != NULL && first->size > 1)
	{
		tmp = first->values[0];
		first->values[0] = first->values[1];
		first->values[1] = tmp;
	}
	if (second != NULL && second->size > 1)
	{
		tmp = second->values[0];
		second->values[0] = second->values[1];
		second->values[1] = tmp;
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

void	push(t_deque *first, t_deque *second, bool silent_mode, char to)
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

void	rotate(t_deque *first, t_deque *second, bool silent_mode)
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

void	reverse_rotate(t_deque *first, t_deque *second, bool silent_mode)
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
