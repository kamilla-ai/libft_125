/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:57:19 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/03 14:25:06 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (size > 0 && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	array = (void *)malloc(count * size);
	if (array == NULL)
	{
		return (NULL);
	}
	ft_bzero(array, (count * size));
	return (array);
}
