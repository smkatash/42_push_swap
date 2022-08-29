/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:43:00 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:22:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*str;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (n > i && (dst || str))
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
