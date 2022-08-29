/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:53:10 by ktashbae          #+#    #+#             */
/*   Updated: 2022/03/29 18:02:44 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen((char *)src);
	n = dstsize - len_d - 1;
	if (dstsize <= len_d)
	{
		return (dstsize + len_s);
	}
	while (src[i] != '\0' && n > i)
	{
		dst[len_d] = src[i];
		len_d++;
		i++;
	}
	dst[len_d] = '\0';
	return (len_d + ft_strlen((char *)&src[i]));
}
