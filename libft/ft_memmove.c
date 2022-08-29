/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:23:11 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/04 07:09:01 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*str;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dest > str)
	{
		while (len > 0)
		{
			dest[len - 1] = str[len - 1];
			len--;
		}
	}
	else if (dest < str)
	{
		ft_memcpy(dest, str, len);
	}
	return (dest);
}
