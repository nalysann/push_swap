/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:33:59 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:34:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_io.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_throw(const char *error_message, int error_code)
{
	if (error_message != NULL)
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putendl_fd(error_message, STDERR_FILENO);
	}
	exit(error_code);
}
