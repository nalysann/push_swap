/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:45:03 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 17:45:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

#include <stddef.h>

int		ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, (char **)NULL, 10));
}
