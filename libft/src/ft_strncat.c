/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:25:29 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:25:31 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;
	size_t	s2_nlen;

	s = s1;
	s1 += ft_strlen(s1);
	s2_nlen = ft_strnlen(s2, n);
	s1[s2_nlen] = '\0';
	ft_memcpy(s1, s2, s2_nlen);
	return (s);
}
