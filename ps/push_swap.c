/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:25:44 by ktashbae          #+#    #+#             */
/*   Updated: 2022/06/05 14:20:44 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_form	*stack;

	if (argc < 2)
		exit(0);
	stack = get_input(&argv[1]);
	sort_and_index(stack);
	sort_and_merge(stack);
	free_form(stack);
	return (0);
}
