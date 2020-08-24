/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:10:43 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:10:44 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*loc;

	loc = ft_memchr(src, c, n);
	if (loc != NULL)
		return (ft_mempcpy(dst, src, loc - src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}
