/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:03:15 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 15:43:06 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	temp;

	count = nbr_len(n);
	temp = (long)n;
	if (n < 0)
	{
		temp = -temp;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		str[count] = 48 + (temp % 10);
		temp = temp / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
	}
	return (str);
}
