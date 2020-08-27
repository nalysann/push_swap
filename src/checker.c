/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:14:00 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:14:02 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"
#include "utils.h"
#include "validation.h"

#include "ft_error.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void		handle_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strequ(line, "sa"))
		swap(a, NULL, true);
	else if (ft_strequ(line, "sb"))
		swap(NULL, b, true);
	else if (ft_strequ(line, "ss"))
		swap(a, b, true);
	else if (ft_strequ(line, "pa"))
		push(a, b, true, 'a');
	else if (ft_strequ(line, "pb"))
		push(b, a, true, 'b');
	else if (ft_strequ(line, "ra"))
		rotate(a, NULL, true);
	else if (ft_strequ(line, "rb"))
		rotate(NULL, b, true);
	else if (ft_strequ(line, "rr"))
		rotate(a, b, true);
	else if (ft_strequ(line, "rra"))
		reverse_rotate(a, NULL, true);
	else if (ft_strequ(line, "rrb"))
		reverse_rotate(NULL, b, true);
	else if (ft_strequ(line, "rrr"))
		reverse_rotate(a, b, true);
	else
		ft_throw(ERROR_MSG, E_OPERATION);
}

int				main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		*line;

	if (argc == 1)
		ft_throw(NULL_MSG, E_NONE);
	if (!is_valid_input(argc, argv))
		ft_throw(ERROR_MSG, E_VALUE);
	initialize_stack(&a, 1, argc, argv);
	initialize_stack(&b, 0, 0, argv);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		handle_operation(line, &a, &b);
		free(line);
	}
	if (is_sorted(&a) && b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
