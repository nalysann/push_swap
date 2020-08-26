/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:28:39 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:28:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "hd_get_next_line.h"

#include <stddef.h>
#include <unistd.h>

static char		*process_buffer(char **buffer, char *endl)
{
	char	*str;
	char	*tmp;

	str = (endl ? ft_strndup(*buffer, endl - *buffer) : *buffer);
	tmp = (endl ? *buffer : NULL);
	*buffer = (endl ? ft_strdup(endl + 1) : NULL);
	ft_strdel(&tmp);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buffers[FD_MAX];
	char			buf[BUF_SIZE + 1];
	ssize_t			ret;
	char			*endl;
	char			*tmp;

	if (!buffers[fd])
		buffers[fd] = ft_strnew(0);
	endl = ft_strchr(buffers[fd], '\n');
	while (!endl && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = buffers[fd];
		buffers[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n') && (endl = ft_strchr(buffers[fd], '\n')))
			break ;
	}
	*line = process_buffer(&buffers[fd], endl);
	return ((ret < 0 || ((ret == 0) && !buffers[fd])) ? (int)ret : 1);
}
