/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:29:08 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:29:20 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOL_H
# define FT_STRTOL_H

typedef struct	s_strtol
{
	const char		*str;
	int				base;
	int				sign;
	int				c;
	int				any;
	unsigned long	res;
}				t_strtol;

#endif
