/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:57:09 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:17:35 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whitespace_and_get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
	{
		(*i)++;
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

static long long	convert_str_to_num(const char *str, int *i, int *sign)
{
	long long	num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if ((*sign == 1 && num > __LONG_MAX__ / 10) || (*sign == 1
				&& num >= __LONG_MAX__ / 10 && str[*i] > '7'))
		{
			return (-1);
		}
		else if ((*sign == -1 && num > __LONG_MAX__ / 10) || (*sign == -1
				&& num >= __LONG_MAX__ / 10 && str[*i] > '7'))
		{
			return (0);
		}
		num = num * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	num;

	i = 0;
	num = 0;
	sign = 1;
	sign = skip_whitespace_and_get_sign(str, &i);
	num = convert_str_to_num(str, &i, &sign);
	num = num * sign;
	return (num);
}
