# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 16:45:44 by asanthos          #+#    #+#              #
#    Updated: 2022/02/10 17:41:40 by asanthos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	srcs/main.c srcs/rotate_rev.c srcs/rotate.c srcs/sort.c srcs/swap.c srcs/sort_small.c srcs/sort_five.c srcs/compare.c srcs/helpers.c srcs/parser_helpers.c srcs/sort_last.c srcs/compare_b.c srcs/rot.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

$(NAME): ${OBJS}
	@make -C ./ft_libft
	@cp ./ft_libft/libft.a ./srcs/libft.a
	$(CC) $(SRCS) ./srcs/libft.a -o $(NAME)

all:	${NAME}

clean:
	@make clean -C ./ft_libft
	${RM} ${OBJS}

fclean: clean
	@make fclean -C ./ft_libft
	${RM} ${NAME}

re: fclean all
