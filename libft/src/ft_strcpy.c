/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:20:31 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:20:33 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strcpy(char *dst, const char *src)
{
	return (ft_memcpy(dst, src, ft_strlen(src) + 1));
}
