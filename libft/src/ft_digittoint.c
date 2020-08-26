/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digittoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:47:06 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 17:47:10 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int		ft_digittoint(int c)
{
	if (ft_isxdigit(c))
	{
		return (ft_isdigit(c) ? c - '0' : c - 'a');
	}
	else
	{
		return (0);
	}
}
