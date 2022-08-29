/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:54:21 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/03 17:43:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp_f(const char c, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (c == s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup_f(char *dst, char *src, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		dst[i] = src[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen((char *)s1);
	while (s1[start] != '\0' && ft_strncmp_f(s1[start], set) == 1)
	{
		start++;
	}
	while (start < end && ft_strncmp_f(s1[end - 1], set) == 1)
	{
		end--;
	}
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	str = ft_strdup_f(str, (char *)s1, start, end);
	return (str);
}
