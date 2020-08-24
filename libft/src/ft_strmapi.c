/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:24:56 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:24:58 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (!(str = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
