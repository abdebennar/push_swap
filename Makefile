# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abennar <abennar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 17:23:39 by abennar           #+#    #+#              #
#    Updated: 2024/01/27 15:13:19 by abennar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push-swap/algo_utils.c push-swap/error_input.c \
	push-swap/extra_func.c push-swap/mem__free.c \
	push-swap/push__cmd.c push-swap/push_swap.c \
	push-swap/rev_rt_cmd.c push-swap/rotate_cmd.c \
	push-swap/shift_stack.c push-swap/sort__algo.c \
	push-swap/stack_utils.c push-swap/swap__cmd.c \
	push-swap/teny__sort.c push-swap/chck_input.c
B_SRC = bonus/checker_bonus.c bonus/error_input_bonus.c \
	bonus/push__cmd_bonus.c bonus/rev_rt_cmd_bonus.c \
	bonus/rotate_cmd_bonus.c bonus/stack_utils_bonus.c \
	bonus/swap__cmd_bonus.c bonus/utils_bonus.c \
	bonus/mem_free_bonus.c bonus/chck_input_bonus.c

NAME = push_swap
BONUS = checker
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror 


all : libft $(NAME)

libft :
	$(MAKE) -C ./libft

$(NAME) : $(SRC) ./push-swap/push_swap.h
	$(CC) $(CFLAGS) $(LIBFT) $(SRC) -o $@

bonus : libft $(BONUS)

$(BONUS) : $(B_SRC) ./bonus/checker_bonus.h
	$(CC) $(CFLAGS) $(LIBFT) $(B_SRC) -o $@

clean :
	$(MAKE) clean -C ./libft
	
fclean :
	$(MAKE) fclean -C ./libft
	rm -f push_swap
	rm -f checker

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : libft clean fclean re