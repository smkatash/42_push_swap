/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:56:36 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:22:44 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (len > 0)
	{
		p[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (p - len);
}
