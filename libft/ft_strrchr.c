/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:19:04 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:33 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	*buf;

	i = 0;
	p = (char *)s;
	buf = 0;
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
		{
			buf = &p[i];
		}
		i++;
	}
	if (c == 0)
	{
		return (&p[i]);
	}
	return (buf);
}
