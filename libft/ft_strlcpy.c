/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:47:11 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:20 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	if (dstsize == 0)
		return (len_s);
	while (i < len_s && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}	
	dst[i] = '\0';
	return (len_s);
}
