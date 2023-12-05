/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:59:21 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:22:29 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*array;
	int		i;

	len = ft_strlen(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (array == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
