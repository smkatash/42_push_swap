/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:25:50 by ktashbae          #+#    #+#             */
/*   Updated: 2022/06/05 12:08:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_form	*stack_init(unsigned int size)
{
	t_form	*stack;

	stack = malloc(sizeof(t_form));
	if (!stack)
		return (NULL);
	stack->stack = malloc(size * sizeof(int));
	if (!stack->stack)
		return (NULL);
	stack->size = size;
	stack->top = 0;
	return (stack);
}

t_form	*reverse_stack(t_form *stack)
{
	t_form	*reversed;

	reversed = stack_init(BUFFER);
	while (stack->top >= 0)
		reversed->stack[reversed->top++] = stack->stack[stack->top--];
	--reversed->top;
	free_form(stack);
	return (reversed);
}

void	loop_command(char *cmd, t_form *a, t_form *b, int n)
{
	if (n <= 0)
		return ;
	while (n > 0)
	{
		command(cmd, a, b);
		n--;
	}
}
