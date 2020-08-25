/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:43:22 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:43:23 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "pf_handle_placeholder.h"

#include <stdarg.h>
#include <stddef.h>

char	*handle_percent(t_fields *fields, va_list ap)
{
	char	*result;

	if (!(result = ft_strnew(1)))
		return (NULL);
	result[0] = '%';
	(void)fields;
	(void)ap;
	return (result);
}
