/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:25:59 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 15:20:55 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <limits.h>
# include <string.h>

# define BUFFER 1024
# define CHUNK 50
# define SIMPLE 5

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define A "a"
# define B "b"

typedef struct s_form
{
	int				*stack;
	unsigned int	size;
	int				top;
}	t_form;

// Init and get input data
t_form	*stack_init(unsigned int size);
t_form	*get_input(char **str);
int		get_data(char *src, t_form *stack);

//Semantic check of the input 
int		check_limit_insert(char *src, int *num);
int		check_int(char *src);
int		check_duplicate(t_form *stack, int num);
t_form	*reverse_stack(t_form *stack);
int		sorted_stack(t_form *stack);

// Commands
void	swap(t_form *stack);
void	rotate(t_form *stack);
void	reverse_rotate(t_form *stack);
void	push(t_form *src, t_form *dest);
void	command(char *command, t_form *a, t_form *b);
void	loop_command(char *cmd, t_form *a, t_form *b, int n);

// Seach for min and max values
int		search_min(t_form *stack);
int		search_max(t_form *stack);
int		search_next_max(t_form *stack, int num);
int		search_next_min(t_form *stack, int num);

// Indexing and sorting
void	sort_and_index(t_form *stack);
void	sort_and_merge(t_form *stack);
void	split_and_shuffle(t_form *stack, char *s, int num);
void	sort_simple(t_form *a, t_form *b);
void	sort_advanced(t_form *a, t_form *b);
void	push_splits(t_form *a, t_form *b, int max, int min);
void	sort_advanced(t_form *a, t_form *b);
void	split_push(t_form *a, t_form *b, int max, int min);
void	sort_splits(t_form *a, t_form *b);
void	sort_split_pa(t_form *a, t_form *b);
void	pre_sort(t_form *stack, int max, int min);
void	pre_sort_split(t_form *stack, int max, int min);

//Check for errors and free 
void	check_errors(int status, t_form *stack);
void	free_arr(char **arr);
void	ft_error(char *message);
void	free_form(t_form *stack);

#endif