# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 13:39:59 by ktashbae          #+#    #+#              #
#    Updated: 2022/08/29 15:26:38 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS := checker

SRC := src/push_swap.c \

PSRC := src/get_input.c src/index_stack.c src/search.c src/sort_simple.c \
src/commands.c src/ps_utils.c src/sort_stack.c src/sort_advanced.c src/advanced_helper.c src/helper.c \

BNSRC := bonus/ps_bonus.c bonus/ps_utils_bonus.c \

LIBFTSRC := libft/ft_isalpha.c libft/ft_isdigit.c \
libft/ft_isalnum.c libft/ft_isascii.c \
libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c \
libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c \
libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c \
libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c \
libft/ft_strnstr.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c \
libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c \
libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_isspace.c \

GNLSRC := gnL/get_next_line.c gnL/get_next_line_utils.c \

OBJ := ${SRC:%.c=%.o}
PSOBJ := ${PSRC:%.c=%.o}
LIBFTOBJ := ${LIBFTSRC:%.c=%.o}
BNSOBJ := ${BNSRC:%.c=%.o}
GNLOBJ := ${GNLSRC:%.c=%.o}
CC := cc
CFLAGS := -Wall -Wextra -Werror
HEADER := include/push_swap.h
BNSHEADER := include/push_swap_bonus.h
RM := rm -f

all: ${NAME}

${NAME} : ${OBJ} ${PSOBJ} ${LIBFTOBJ} ${HEADER}
	@${CC} ${OBJ} ${PSOBJ} ${LIBFTOBJ} -o ${NAME}
	@echo "\033[0;32m [push_swap is compiled.]"
	
${BONUS} : ${PSOBJ} ${BNSOBJ} ${LIBFTOBJ} ${GNLOBJ} ${BNSHEADER}
	@${CC} ${PSOBJ} ${BNSOBJ} ${LIBFTOBJ} ${GNLOBJ} -o ${BONUS}
	@echo "\033[0;33m [checker is compiled.]"

bonus: ${BONUS}

both : ${NAME} ${BONUS}

%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ} ${PSOBJ} ${BNSOBJ} ${LIBFTOBJ} ${GNLOBJ}

fclean: clean
	@${RM} ${NAME} ${BONUS}

re: fclean all

rebonus: fclean bonus

.PHONY:	all clean fclean re bonus
