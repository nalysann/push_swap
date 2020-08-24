/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:45:19 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 17:45:22 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

#include <stddef.h>

long	ft_atol(const char *str)
{
	return (ft_strtol(str, (char **)NULL, 10));
}
