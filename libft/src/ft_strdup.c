/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:20:50 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:20:52 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	void	*new;

	len = ft_strlen(s) + 1;
	if (!(new = malloc(len)))
		return (NULL);
	return (ft_memcpy(new, s, len));
}
