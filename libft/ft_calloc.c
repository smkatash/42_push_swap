/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:25:10 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/21 11:13:57 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t_size;
	void	*p;

	t_size = count * size;
	if (size != 0 && count > 65535 / size)
		return (NULL);
	p = malloc(t_size);
	if (p == 0)
	{
		return (0);
	}
	ft_bzero(p, t_size);
	return (p);
}
