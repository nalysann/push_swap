/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:46:36 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 11:46:38 by nalysann         ###   ########.fr       */
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

void			initialize_stack(t_stack *stack, int beg, int end, char **argv);
bool			is_sorted(t_stack *stack);
int				get_value(t_stack *stack, size_t pos);

#endif
