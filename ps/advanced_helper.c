/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:22:54 by ktashbae          #+#    #+#             */
/*   Updated: 2022/06/05 12:11:22 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	scan_to_zero(t_form *stack, int max, int min)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->stack[i] <= max && stack->stack[i] >= min)
			return (i);
		i--;
	}
	return (0);
}

static int	scan_to_top(t_form *stack, int max, int min)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->stack[i] <= max && stack->stack[i] >= min)
			return (i);
		i++;
	}
	return (0);
}

static int	scan_split(t_form *stack, int position)
{
	int	i;

	i = stack->top;
	while (i >= 0 && stack->stack[i] != position)
		i--;
	return (i);
}

void	pre_sort(t_form *stack, int max, int min)
{
	int	position;
	int	top;
	int	lower;

	top = scan_to_top(stack, max, min);
	lower = scan_to_zero(stack, max, min);
	if (top < stack->top - lower)
		position = top;
	else
		position = lower;
	split_and_shuffle(stack, A, stack->stack[position]);
}

void	pre_sort_split(t_form *stack, int max, int min)
{
	int	position;
	int	top;
	int	lower;

	top = scan_split(stack, min);
	lower = scan_split(stack, max);
	if (top < stack->top - lower)
		position = top;
	else
		position = lower;
	split_and_shuffle(stack, B, stack->stack[position]);
}
