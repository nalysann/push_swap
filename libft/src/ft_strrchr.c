/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:58 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:27:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char		*found;
	const char		*p;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	while ((p = ft_strchr(s, c)))
	{
		found = p;
		s = p + 1;
	}
	return ((char *)found);
}
