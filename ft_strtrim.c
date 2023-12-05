/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:06:54 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 16:02:08 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start_index(const char *s, const char *set)
{
	int	start;

	start = 0;
	while (s[start] && ft_strchr(set, s[start]) != NULL)
	{
		start++;
	}
	return (start);
}

static int	find_end_index(const char *s, const char *set, int start)
{
	int	end;

	end = ft_strlen(s);
	while (end > start && ft_strchr(set, s[end - 1]) != NULL)
	{
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1 || !set)
	{
		return (NULL);
	}
	start = find_start_index(s1, set);
	end = find_end_index(s1, set, start);
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(res, s1 + start, end - start + 1);
	return (res);
}
