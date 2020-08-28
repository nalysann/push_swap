/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:50:25 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 13:50:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "deque.h"
#include "utils.h"
#include "validation.h"

#include "ft_error.h"
#include "ft_string.h"

#include <stddef.h>

static void		sort_small(t_deque *deque)
{
	int		max_idx;

	if (deque->size == 1)
		return ;
	if (deque->size == 2)
	{
		if (deque->values[0] > deque->values[1])
			swap(deque, NULL, false);
		return ;
	}
	else if (deque->size == 3)
	{
		max_idx = get_max_index(deque);
		if (max_idx == 0)
			rotate(deque, NULL, false);
		if (max_idx == 1)
			reverse_rotate(deque, NULL, false);
		if (deque->values[0] > deque->values[1])
			swap(deque, NULL, false);
	}
}

void			sort_deque(t_deque *a, t_deque *b)
{
	t_ops	best;
	size_t	margin;

	ft_bzero(&best, sizeof(best));
	margin = (a->size / 8 > 2 ? a->size / 8 : 2);
	push(b, a, false, 'b');
	push(b, a, false, 'b');
	while (a->size > margin)
	{
		get_best_ops(a, b, &best);
		handle_ops(a, b, &best);
		push(b, a, false, 'b');
	}
	move_after_margin(a, b);
	move_back(a, b);
}

int				main(int argc, char *argv[])
{
	t_deque		a;
	t_deque		b;

	if (argc == 1)
		ft_throw(NULL_MSG, E_NONE);
	if (!is_valid_input(argc, argv))
		ft_throw(ERROR_MSG, E_VALUE);
	initialize_deque(&a, 1, argc, argv);
	initialize_deque(&b, argc, argc, argv);
	if (is_sorted(&a))
		ft_throw(NULL_MSG, E_NONE);
	if (a.size <= 3)
		sort_small(&a);
	else
		sort_deque(&a, &b);
}
