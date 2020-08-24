/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:25:44 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:25:45 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if ((*s1 == '\0' && *s2 == '\0') || (*s1++ != *s2++))
			return (*(const unsigned char *)(s1 - 1) -
					*(const unsigned char *)(s2 - 1));
	}
	return (0);
}
