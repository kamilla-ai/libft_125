/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:06:48 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 15:39:04 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*findstr(size_t len, const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] && haystack[i + j] == needle[j] && i
				+ j < len)
			{
				j++;
			}
			if (j == needle_len)
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	return (findstr(len, haystack, needle));
}
