/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:59:12 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_min(t_form *stack)
{
	int	i;
	int	min;

	i = 1;
	min = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	search_max(t_form *stack)
{
	int	i;
	int	max;

	i = 1;
	max = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	search_next_max(t_form *stack, int num)
{
	int	i;
	int	max;

	max = search_max(stack);
	if (num > max || stack->top < 0)
		return (num);
	i = 0;
	while (i <= stack->top)
	{
		if (stack->stack[i] > num && max > stack->stack[i])
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	search_next_min(t_form *stack, int num)
{
	int	i;
	int	min;

	min = search_min(stack);
	if (num <= min || stack->top < 0)
		return (num);
	i = 0;
	while (i <= stack->top)
	{
		if (stack->stack[i] < num && min < stack->stack[i])
			min = stack->stack[i];
		i++;
	}
	return (min);
}
