/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:19:59 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 13:20:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_stdlib.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

void	initialize_deque(t_deque *deque, int beg, int argc, char *argv[])
{
	int		i;

	deque->values = (int *)malloc((argc - 1) * sizeof(int));
	deque->size = 0;
	if (deque->values == NULL)
		ft_throw(MEMORY_MSG, E_MEMORY);
	i = beg;
	while (i < argc)
	{
		push_back(deque, ft_atoi(argv[i]));
		++i;
	}
}

bool	is_sorted(t_deque *deque)
{
	size_t	i;

	i = 0;
	while (i + 1 < deque->size)
	{
		if (deque->values[i] > deque->values[i + 1])
			return (false);
		++i;
	}
	return (true);
}
