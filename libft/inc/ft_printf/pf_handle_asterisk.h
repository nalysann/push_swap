/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_asterisk.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:29:36 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/25 18:29:37 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_ASTERISK_H
# define PF_HANDLE_ASTERISK_H

# include "pf_handle_placeholder.h"

# include <stdarg.h>

void	handle_asterisk(t_fields *fields, va_list ap);

#endif
