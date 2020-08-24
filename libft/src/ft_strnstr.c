/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:46 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:26:47 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
