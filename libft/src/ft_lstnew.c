/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:10:03 by nalysann          #+#    #+#             */
/*   Updated: 2020/07/13 18:10:05 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include <stddef.h>
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*link;

	if (!(link = malloc(sizeof(*link))))
		return (NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!content_size || !(link->content = malloc(content_size)))
		{
			ft_memdel((void **)&link);
			return (NULL);
		}
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
