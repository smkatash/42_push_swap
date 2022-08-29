/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:03:13 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:19:23 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	command_checker(char *command, t_form *a, t_form *b)
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
	else if (ft_strncmp(command, RRR, 3) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		ft_error("Error");
}

void	check_length(char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "rr", 2) == 0 && len >= 5)
		ft_error("Error");
	else if (ft_strncmp(cmd, "rr", 2) != 0 && len > 3)
		ft_error("Error");
}

void	get_commands(t_form *a, t_form *b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		if (ft_strncmp(cmd, "\n", 1) == 0)
			break ;
		check_length(cmd);
		command_checker(cmd, a, b);
		free(cmd);
	}
	if (sorted_stack(a) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(cmd);
}
