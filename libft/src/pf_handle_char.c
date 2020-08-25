/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:40:36 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:40:40 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "pf_handle_placeholder.h"

#include <stdarg.h>
#include <stddef.h>

char	*handle_char(t_fields *fields, va_list ap)
{
	char	*result;

	if (!(result = ft_strnew(1)))
		return (NULL);
	result[0] = (char)va_arg(ap, int);
	(void)fields;
	return (result);
}
