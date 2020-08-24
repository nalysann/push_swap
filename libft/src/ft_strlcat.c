/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:56 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:21:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	len;

	dst_len = ft_strnlen(dst, size);
	src_len = ft_strlen(src);
	if (dst_len != size)
	{
		dst += dst_len;
		size -= dst_len;
		if (src_len >= size)
			len = size - 1;
		else
			len = src_len;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (dst_len + src_len);
}
