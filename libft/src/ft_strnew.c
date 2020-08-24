/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:26:25 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:26:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

#include <stddef.h>
#include <stdint.h>

char	*ft_strnew(size_t size)
{
	return ((size == SIZE_MAX) ? NULL : ft_memalloc(size + 1));
}
