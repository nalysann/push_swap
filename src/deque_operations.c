/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:19:54 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 13:19:55 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

#include "ft_string.h"

void	push_back(t_deque *deque, int value)
{
	deque->values[deque->size] = value;
	++deque->size;
}

void	push_front(t_deque *deque, int value)
{
	ft_memmove(deque->values + 1, deque->values, deque->size * sizeof(int));
	deque->values[0] = value;
	++deque->size;
}

int		pop_back(t_deque *deque)
{
	--deque->size;
	return (deque->values[deque->size]);
}

int		pop_front(t_deque *deque)
{
	int		value;

	value = deque->values[0];
	--deque->size;
	ft_memmove(deque->values, deque->values + 1, deque->size * sizeof(int));
	return (value);
}
