/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:12:24 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:12:27 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include <stddef.h>

typedef struct	s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*back;
	t_node	*front;
	size_t	size;
}				t_stack;

void			push_back(t_stack *stack, t_node *node);
void			push_front(t_stack *stack, t_node *node);
t_node			*pop_back(t_stack *stack);
t_node			*pop_front(t_stack *stack);

void			print_stacks(t_stack *a, t_stack *b);
bool			is_sorted(t_stack *stack);

#endif
