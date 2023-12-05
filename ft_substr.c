/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:07:03 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:23:42 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	alloc_size;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	alloc_size = ft_strlen(s + start);
	if (alloc_size > len)
		alloc_size = len;
	subs = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (subs == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < alloc_size && s[start + i] != '\0')
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
