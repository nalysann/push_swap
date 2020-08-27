/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digittoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:34:28 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:34:29 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int		ft_digittoint(int c)
{
	if (ft_isxdigit(c))
		return (ft_isdigit(c) ? c - '0' : c - 'a');
	else
		return (0);
}
