/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:05:24 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:22:18 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putstr(const char *s, char c, int *current)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s[*current] != '\0' && s[*current] == c)
	{
		(*current)++;
	}
	while (s[*current + len] != '\0' && s[*current + len] != c)
	{
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[*current];
		(*current)++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

static int	numberofstrings(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		current;

	if (s == NULL)
	{
		return (NULL);
	}
	current = 0;
	i = 0;
	count = numberofstrings(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	while (i < count)
	{
		result[i] = putstr(s, c, &current);
		i++;
	}
	result[count] = NULL;
	return (result);
}
