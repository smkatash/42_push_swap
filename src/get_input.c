/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:42:23 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:17 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_int(char *src)
{
	unsigned int	i;
	int				check;
	unsigned int	neg;

	i = 0;
	check = 1;
	neg = 0;
	while (src[i] != '\0' && check == 1)
	{
		if (src[i] == '-' && neg < 1)
			neg++;
		else if (ft_isdigit(src[i]) != 1)
			check = 0;
		i++;
	}
	return (check);
}

int	check_limit_insert(char *src, int *num)
{
	int	check;
	int	sign;

	*num = 0;
	check = 1;
	sign = 1;
	while (ft_isspace_p(*src) == 1)
		src++;
	if (*src == '+' || *src == '-')
	{
		if (*src++ == '-')
			sign = -1;
	}
	while (*src >= '0' && *src <= '9')
	{
		*num = 10 * *num + (*src - '0');
		if (*num < 0 || (*num == INT_MAX && sign > 0) || \
		(*num == INT_MIN && sign < 0))
			check = 0;
		src++;
	}
	*num *= sign;
	return (check);
}

int	check_duplicate(t_form *stack, int num)
{
	int			i;
	static int	null;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->stack[i] == 0 && num == 0 && null < 1)
		{
			null = null + 1;
			return (1);
		}
		if (stack->stack[i] == num)
			return (0);
		i--;
	}
	return (1);
}

int	get_data(char *src, t_form *stack)
{
	int				status;
	char			**arr;
	int				num;
	unsigned int	i;

	i = 0;
	status = 0;
	arr = ft_split(src, ' ');
	while (arr[i] != NULL && status == 0)
	{
		if (check_int(arr[i]) == 0)
			status = 1;
		if (check_limit_insert(arr[i], &num) == 0)
			status = 2;
		if (check_duplicate(stack, num) == 0)
			status = 3;
		else
		{
			stack->stack[stack->top] = num;
			stack->top++;
		}
		i++;
	}
	free_arr(arr);
	return (status);
}

t_form	*get_input(char **str)
{
	unsigned int	i;
	t_form			*stack;
	int				status;

	i = 0;
	status = 0;
	stack = stack_init(BUFFER);
	while (str[i] && status == 0)
	{
		status = get_data(str[i], stack);
		i++;
	}
	check_errors(status, stack);
	--stack->top;
	stack = reverse_stack(stack);
	return (stack);
}
