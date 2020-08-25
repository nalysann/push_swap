/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_length.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:30:17 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:30:18 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_LENGTH_H
# define PF_HANDLE_LENGTH_H

# include <stdarg.h>

long long			get_signed(va_list ap, int length);
unsigned long long	get_unsigned(va_list ap, int length);
long double			get_float(va_list ap, int length);

#endif
