/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:56:11 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/03 16:07:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcpy_d(char *str, char *s1, char *s2, size_t pref)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = pref;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[count] = s2[i];
		i++;
		count++;
	}
	str[count] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	pref;
	size_t	suff;
	char	*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pref = ft_strlen(s1);
	suff = ft_strlen(s2);
	str = malloc(sizeof(char) * (pref + suff + 1));
	if (str)
	{
		ft_strlcpy_d(str, (char *)s1, (char *)s2, pref);
		return (str);
	}
	return (NULL);
}
