/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:24:28 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:42 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	split_and_shuffle(t_form *stack, char *s, int num)
{
	int	target;

	target = stack->top;
	while (target >= 0 && stack->stack[target] != num)
		target--;
	if (target < 0)
		return ;
	else if (target >= (stack->top / 2))
	{
		if (ft_strncmp(s, A, 1) == 0)
			loop_command(RA, stack, NULL, stack->top - target);
		else if (ft_strncmp(s, B, 1) == 0)
			loop_command(RB, NULL, stack, stack->top - target);
	}
	else if (target < (stack->top / 2))
	{
		if (ft_strncmp(s, A, 1) == 0)
			loop_command(RRA, stack, NULL, target + 1);
		else if (ft_strncmp(s, B, 1) == 0)
			loop_command(RRB, NULL, stack, target + 1);
	}
}

void	sort_split_pa(t_form *a, t_form *b)
{
	int	next_to_push;
	int	to_push_on;

	next_to_push = b->stack[b->top];
	to_push_on = search_next_max(a, next_to_push);
	if (a->top >= 0 && next_to_push == to_push_on)
		to_push_on = search_min(a);
	split_and_shuffle(a, A, to_push_on);
	command(PA, a, b);
}

void	sort_splits(t_form *a, t_form *b)
{
	while (b->top >= 0)
	{
		pre_sort_split(b, search_max(b), search_min(b));
		sort_split_pa(a, b);
	}
}

void	split_push(t_form *a, t_form *b, int max, int min)
{
	int	chunk;

	chunk = max - min;
	while (chunk >= 0)
	{
		pre_sort(a, max, min);
		command(PB, a, b);
		chunk--;
	}
}

void	sort_advanced(t_form *a, t_form *b)
{
	size_t	splits;
	size_t	part;
	int		max;
	int		min;

	--b->top;
	splits = (a->top + 1) / CHUNK + 1;
	part = (a->top + 1) / splits;
	max = search_max(a);
	while (splits >= 1)
	{
		if (splits == 1)
			min = search_min(a);
		else
			min = max - part;
		split_push(a, b, max, min);
		sort_splits(a, b);
		max = min - 1;
		splits--;
	}
	min = search_min(a);
	split_and_shuffle(a, A, min);
}
