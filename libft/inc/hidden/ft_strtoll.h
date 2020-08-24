/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:29:26 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:29:27 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOLL_H
# define FT_STRTOLL_H

typedef struct	s_strtoll
{
	const char			*str;
	int					base;
	int					sign;
	int					c;
	int					any;
	unsigned long long	res;
}				t_strtoll;

#endif
