/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:56:19 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:26 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	insertion_sort(int *stack, unsigned int size)
{
	unsigned int	i;
	int				j;
	int				temp;

	i = 1;
	while (i < size)
	{
		j = i - 1;
		temp = stack[i];
		while (j >= 0 && stack[j] > stack[j + 1])
		{
			stack[j + 1] = stack[j];
			stack[j] = temp;
			j--;
		}
		i++;
	}
}

static int	*get_sorted_stack(t_form *stack)
{
	int				*temp;
	size_t			size;

	size = stack->top + 1;
	temp = malloc(size * sizeof(int));
	if (!temp)
		return (NULL);
	ft_memcpy(temp, stack->stack, size * sizeof(int));
	insertion_sort(temp, size);
	return (temp);
}

void	sort_and_index(t_form *stack)
{
	int		*temp_stack;
	int		*sorted_stack;
	size_t	index;
	int		i;

	i = 0;
	temp_stack = ft_calloc(stack->top + 1, sizeof(int));
	sorted_stack = get_sorted_stack(stack);
	while (i <= stack->top)
	{
		index = 0;
		while (sorted_stack[index] != stack->stack[i])
			index++;
		temp_stack[i] = index;
		i++;
	}
	ft_memcpy(stack->stack, temp_stack, (stack->top + 1) * sizeof(int));
	free(sorted_stack);
	free(temp_stack);
}
