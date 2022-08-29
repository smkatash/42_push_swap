/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:17:10 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:45 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	shuffle_and_sort(t_form *a)
{
	if (a->stack[0] > a->stack[1])
	{
		if (a->stack[1] < a->stack[2] && a->stack[0] > a->stack[2])
			command(SA, a, NULL);
		else if (a->stack[1] < a->stack[2] && a->stack[0] < a->stack[2])
			command(RA, a, NULL);
	}
	else if (a->stack[0] < a->stack[1])
	{
		if (a->stack[1] > a->stack[2] && a->stack[2] < a->stack[0])
		{
			command(SA, a, NULL);
			command(RA, a, NULL);
		}
		else if (a->stack[1] > a->stack[2] && a->stack[2] > a->stack[0])
			command(RRA, a, NULL);
		else if (a->stack[1] < a->stack[2] && a->stack[2] > a->stack[0])
		{
			command(SA, a, NULL);
			command(RRA, a, NULL);
		}
	}
}

void	sort_b_pa(t_form *a, t_form *b)
{
	int	next_to_push;
	int	to_push_on;

	next_to_push = b->stack[b->top];
	to_push_on = search_next_max(a, next_to_push);
	if (next_to_push == to_push_on)
		to_push_on = search_min(a);
	split_and_shuffle(a, A, to_push_on);
	command(PA, a, b);
}

void	pb_shuffle_and_sort_pa(t_form *a, t_form *b)
{
	int	new_top;

	new_top = a->top - 2;
	--b->top;
	loop_command(PB, a, b, new_top);
	shuffle_and_sort(a);
	while (b->top >= 0)
		sort_b_pa(a, b);
	split_and_shuffle(a, A, 0);
}

void	sort_simple(t_form *a, t_form *b)
{
	if (a->top == 1)
		command(SA, a, NULL);
	else if (a->top == 2)
		shuffle_and_sort(a);
	else
		pb_shuffle_and_sort_pa(a, b);
}
