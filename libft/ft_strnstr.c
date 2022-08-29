/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:48:45 by ktashbae          #+#    #+#             */
/*   Updated: 2022/03/29 11:07:52 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (s2[i] == '\0')
		return (s1);
	while (len > i && s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			if (s2[j + 1] == '\0')
			{
				return (&s1[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
