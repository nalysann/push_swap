/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:10:24 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:10:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = NULL;
	if (size && (area = malloc(size)))
		ft_bzero(area, size);
	return (area);
}
