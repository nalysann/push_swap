/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:46:41 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:46:44 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle_float.h"
#include "pf_utils.h"

#include <stddef.h>

void	ulltoa(unsigned long long value, t_string *string)
{
	size_t	length;
	size_t	i;

	length = get_length_unsigned(value, 10);
	i = 0;
	while (i < length)
	{
		string->str[string->len + length - 1 - i] = value % 10 + '0';
		++i;
		value /= 10;
	}
	string->len += length;
}
