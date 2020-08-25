/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:14:00 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:14:01 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "operations.h"
#include "stack.h"
#include "utils.h"
#include "validation.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

void			initialize_stack(t_stack *stack, int beg, int end, char *argv[])
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

static void		execute_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strequ(line, "sa"))
		swap(a, NULL);
	else if (ft_strequ(line, "sb"))
		swap(NULL, b);
	else if (ft_strequ(line, "ss"))
		swap(a, b);
	else if (ft_strequ(line, "pa"))
		push(a, b);
	else if (ft_strequ(line, "pb"))
		push(b, a);
	else if (ft_strequ(line, "ra"))
		rotate(a, NULL);
	else if (ft_strequ(line, "rb"))
		rotate(NULL, b);
	else if (ft_strequ(line, "rr"))
		rotate(a, b);
	else if (ft_strequ(line, "rra"))
		reverse_rotate(a, NULL);
	else if (ft_strequ(line, "rrb"))
		reverse_rotate(NULL, b);
	else if (ft_strequ(line, "rrr"))
		reverse_rotate(a, b);
	else
		ft_throw(ERROR_MSG, E_OPERATION);
}

static void		handle_operations(t_stack *a, t_stack *b, bool verbose)
{
	char	*line;

	line = NULL;
	if (verbose)
		print_stacks(a, b);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		execute_operation(line, a, b);
		if (verbose)
			print_stacks(a, b);
		free(line);
	}
	free(line);
}

int				main(int argc, char *argv[])
{
	bool		verbose;
	t_stack		a;
	t_stack		b;

	if (argc == 1 || (argc == 2 && ft_strequ(argv[1], "-v")))
		ft_throw(NULL_MSG, E_NONE);
	verbose = false;
	if (ft_strequ(argv[1], "-v"))
		verbose = true;
	if (!is_valid_input(argc, argv, verbose))
		ft_throw(ERROR_MSG, E_VALUE);
	initialize_stack(&a, (verbose ? 2 : 1), argc, argv);
	initialize_stack(&b, 0, 0, argv);
	handle_operations(&a, &b, verbose);
	if (is_sorted(&a) && b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
