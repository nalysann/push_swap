/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:29:11 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 09:29:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# ifndef WHITE
#  define WHITE		"\033[0;0m"
# endif

# ifndef RED
#  define RED	"\033[1;31m"
# endif

void	ft_throw(const char *error_message, int error_code);

#endif
