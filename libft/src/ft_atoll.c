/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:45:27 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 17:45:28 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

#include <stddef.h>

long long	ft_atoll(const char *str)
{
	return (ft_strtoll(str, (char **)NULL, 10));
}
