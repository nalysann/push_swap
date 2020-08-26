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

#include "hd_get_next_line.h"

#include "ft_stdlib.h"
#include "ft_string.h"

#include <stddef.h>
#include <unistd.h>

static char		*process_buffer(char **buffer, char *endl)
{
	char	*str;
	char	*tmp;

	str = (endl == NULL ? *buffer : ft_strndup(*buffer, endl - *buffer));
	tmp = (endl == NULL ? NULL : *buffer);
	*buffer = (endl == NULL ? NULL : ft_strdup(endl + 1));
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

	if (buffers[fd] == NULL)
		buffers[fd] = ft_strnew(0);
	endl = ft_strchr(buffers[fd], '\n');
	while (endl == NULL && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = buffers[fd];
		buffers[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n') && (endl = ft_strchr(buffers[fd], '\n')))
			break ;
	}
	*line = (*buffers[fd] != '\0' ? process_buffer(&buffers[fd], endl) : NULL);
	if (*line == NULL)
		ft_strdel(&buffers[fd]);
	return (*line == NULL ? (int)ret : 1);
}
