/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:19:49 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 11:19:51 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

#include <limits.h>
#include <stdbool.h>

#include <stdio.h>

static bool		is_unique(int idx, char *argv[], bool verbose)
{
	int		i;

	i = (verbose ? 2 : 1);
	while (i < idx)
	{
		if (ft_atoll(argv[i]) == ft_atoll(argv[idx]))
			return (false);
		++i;
	}
	return (true);
}

bool			is_valid_input(int argc, char *argv[], bool verbose)
{
	int			i;
	long long	number;
	char		*endptr;

	i = 1;
	if (verbose && ft_strequ(argv[1], "-v"))
		++i;
	while (i < argc)
	{
		number = ft_strtoll(argv[i], &endptr, 10);
		if (*endptr != '\0' ||
			!(INT_MIN <= number && number <= INT_MAX) ||
			!is_unique(i, argv, verbose))
			return (false);
		++i;
	}
	return (true);
}
