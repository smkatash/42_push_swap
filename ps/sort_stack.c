/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:09:11 by ktashbae          #+#    #+#             */
/*   Updated: 2022/06/05 12:10:52 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_and_merge(t_form *stack)
{
	t_form	*a;
	t_form	*b;

	if (sorted_stack(stack) == 0 || stack->top <= 0)
		return ;
	a = stack;
	b = stack_init(a->size);
	if (a->top < SIMPLE)
		sort_simple(a, b);
	else
		sort_advanced(a, b);
	free_form(b);
}
