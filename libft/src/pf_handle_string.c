/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:45:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:45:21 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "pf_handle_placeholder.h"

#include <stdarg.h>

char	*handle_string(t_fields *fields, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fields->precision != GET_DEFAULT && len > fields->precision)
		len = fields->precision;
	return (ft_strndup(str, len));
}
