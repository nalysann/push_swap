/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:20:19 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/28 13:20:20 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdbool.h>
# include <stddef.h>

typedef struct	s_deque
{
	int		*values;
	size_t	size;
}				t_deque;

size_t			get_min_index(t_deque *deque);
size_t			get_max_index(t_deque *deque);
int				get_min_value(t_deque *deque);
int				get_max_value(t_deque *deque);

void			push_back(t_deque *deque, int value);
void			push_front(t_deque *deque, int value);
int				pop_back(t_deque *deque);
int				pop_front(t_deque *deque);

void			initialize_deque(t_deque *deque, int beg, int end,
									char *argv[]);
bool			is_sorted(t_deque *deque);

#endif
