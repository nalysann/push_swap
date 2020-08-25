/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_invalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:42:13 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:42:14 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "pf_handle_placeholder.h"

#include <stdarg.h>
#include <stddef.h>

char	*handle_invalid(t_fields *fields, va_list ap)
{
	char	*result;

	if (!(result = ft_strnew(0)))
		return (NULL);
	ft_bzero(fields, sizeof(*fields));
	(void)ap;
	return (result);
}
