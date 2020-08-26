/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:49:09 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 13:49:11 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "stack.h"
#include "utils.h"
#include "validation.h"

#include "ft_error.h"

static void		sort_3(t_stack *a, t_stack *b)
{
	int		max_idx;

	if (a->size == 1)
		return ;
	if (a->size == 2)
	{
		if (a->front->value > a->back->value)
			swap(a, NULL, false);
		return ;
	}
	else
	{
		max_idx = find_max_elem(a);
		if (max_idx == 0)
			rotate(a, NULL, false);
		if (max_idx == 1)
			reverse_rotate(a, NULL, false);
		if (a->front->value > a->front->next->value)
			swap(a, NULL, false);
	}
}

int				main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		ft_throw(NULL_MSG, E_NONE);
	if (!is_valid_input(argc, argv, false))
		ft_throw(ERROR_MSG, E_VALUE);
	initialize_stack(&a, 1, argc, argv);
	initialize_stack(&b, 0, 0, argv);
	if (is_sorted(&a))
		return ;
	if (a->size <= 3)
		return (sort_3(a, b));
	else
		global_sort(&a, &b);
}
