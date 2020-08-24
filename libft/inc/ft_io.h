/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:29:51 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:29:56 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
int		get_next_line(const int fd, char **line);

#endif
