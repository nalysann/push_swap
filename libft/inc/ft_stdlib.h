/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:30:25 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:30:27 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
char		*ft_itoa(int n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_strdel(char **as);
char		*ft_strnew(size_t size);
long		ft_strtol(const char *str, char **endptr, int base);
long long	ft_strtoll(const char *str, char **endptr, int base);

#endif
