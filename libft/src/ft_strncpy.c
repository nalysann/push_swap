/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:25:55 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:25:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = ft_strnlen(src, n);
	if (len != n)
		ft_bzero(dst + len, n - len);
	return (ft_memcpy(dst, src, len));
}
