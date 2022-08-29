/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:17:54 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_form *stack)
{
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = temp;
}

void	rotate(t_form *stack)
{
	int	temp;
	int	i;
	int	j;

	temp = stack->stack[stack->top];
	i = stack->top;
	j = i - 1;
	while (j >= 0)
		stack->stack[i--] = stack->stack[j--];
	stack->stack[0] = temp;
}

void	reverse_rotate(t_form *stack)
{
	int	temp;
	int	i;
	int	j;

	temp = stack->stack[0];
	i = 0;
	j = i + 1;
	while (j <= stack->top)
		stack->stack[i++] = stack->stack[j++];
	stack->stack[stack->top] = temp;
}

void	push(t_form *src, t_form *dest)
{
	if (src->top == -1)
		return ;
	dest->stack[++dest->top] = src->stack[src->top--];
}

void	command(char *command, t_form *a, t_form *b)
{
	if (ft_strncmp(command, SA, 2) == 0)
		swap(a);
	else if (ft_strncmp(command, SB, 2) == 0)
		swap(b);
	else if (ft_strncmp(command, RA, 2) == 0)
		rotate(a);
	else if (ft_strncmp(command, RB, 2) == 0)
		rotate(b);
	else if (ft_strncmp(command, PA, 2) == 0)
		push(b, a);
	else if (ft_strncmp(command, PB, 2) == 0)
		push(a, b);
	else if (ft_strncmp(command, RRA, 3) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(command, RRB, 3) == 0)
		reverse_rotate(b);
	ft_putendl_fd(command, 1);
}
