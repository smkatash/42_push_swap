/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:24:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/06/05 15:22:55 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_form	*a;
	t_form	*b;
	int		i;

	i = 3;
	if (argc < 2)
		exit(0);
	a = get_input(&argv[1]);
	b = stack_init(a->size);
	--b->top;
	get_commands(a, b);
	free_form(a);
	free_form(b);
	return (0);
}
