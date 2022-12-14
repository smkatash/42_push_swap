/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:08:22 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:22:18 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long	ft_count_num(long n)
{
	long	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	*ft_positive(long num, long count, char *dst)
{
	while (count > 0)
	{
		dst[count - 1] = num % 10 + '0';
		num = num / 10;
		count--;
	}
	return (0);
}

void	*ft_negative(long num, long count, char *dst)
{
	dst[0] = '-';
	num *= -1;
	while (count - 1 > 0)
	{
		dst[count - 1] = num % 10 + '0';
		num = num / 10;
		count--;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	long	count;
	char	*dst;
	long	num;

	num = n;
	count = ft_count_num(num);
	dst = malloc(sizeof(char) * (count + 1));
	if (!dst)
		return (NULL);
	dst[count] = '\0';
	if (num == 0)
		dst[0] = '0';
	else if (num == 1)
		dst[0] = '1';
	else if (num > 0)
		ft_positive (num, count, dst);
	else if (num < 0)
		ft_negative (num, count, dst);
	return (dst);
}
