/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:08:35 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 16:02:44 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while (i < n)
	{
		u1 = (unsigned char)s1[i];
		u2 = (unsigned char)s2[i];
		if (u1 != u2 || u1 == '\0')
		{
			return (u1 - u2);
		}
		i++;
	}
	return (0);
}
