/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:46:21 by nalysann          #+#    #+#             */
/*   Updated: 2020/08/27 10:46:23 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static char		*search_with_longwords(const unsigned char *char_ptr,
										unsigned char uc)
{
	const unsigned long		*long_ptr;
	unsigned long			longword;
	unsigned long			magic;
	unsigned long			mask;
	size_t					i;

	long_ptr = (unsigned long *)char_ptr;
	magic = ~0UL / 0xff * 0xfe << 1 >> 1 | 1;
	mask = 0x0101010101010101 * (unsigned long)uc;
	while (1)
	{
		longword = *long_ptr++;
		if ((((longword + magic) ^ ~longword) & ~magic) ||
			((((longword ^ mask) + magic) ^ ~(longword ^ mask)) & ~magic))
		{
			char_ptr = (const unsigned char *)(long_ptr - 1);
			i = -1;
			while (++i <= sizeof(unsigned long))
				if (char_ptr[i] == uc || char_ptr[i] == '\0')
					return ((char_ptr[i] == uc) ? (char *)(char_ptr + i)
												: NULL);
		}
	}
}

char			*ft_strchr(const char *s, int c)
{
	unsigned char			uc;
	const unsigned char		*char_ptr;

	uc = (unsigned char)c;
	char_ptr = (const unsigned char *)s;
	while ((size_t)char_ptr & (sizeof(unsigned long) - 1))
	{
		if (*char_ptr == uc || *char_ptr == '\0')
			return ((*char_ptr == uc) ? (char *)char_ptr : NULL);
		++char_ptr;
	}
	return (search_with_longwords(char_ptr, uc));
}
