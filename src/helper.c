/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:11:18 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:20 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void	free_form(t_form *stack)
{
	free(stack->stack);
	free(stack);
}

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	sorted_stack(t_form *stack)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j <= stack->top)
	{
		if (stack->stack[j++] > stack->stack[i++])
			return (1);
	}
	return (0);
}

void	check_errors(int status, t_form *stack)
{
	if (status != 0)
	{
		free_form(stack);
		if (status == 1)
			ft_putstr_fd("Error\nNot an integer.\n", 2);
		else if (status == 2)
			ft_putstr_fd("Error\nExceeds an integer size.\n", 2);
		else if (status == 3)
			ft_putstr_fd("Error\nDuplicate.\n", 2);
		else
			ft_putstr_fd("Error\n", 2);
		exit(status);
	}
}
