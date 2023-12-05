/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:36:59 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:23:29 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((const char *)s);
	if (c == '\0')
	{
		return ((char *)&s[len]);
	}
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			return ((char *)s + len);
		}
		len--;
	}
	return (NULL);
}
