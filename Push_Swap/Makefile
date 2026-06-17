# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 16:14:36 by ahoward           #+#    #+#              #
#    Updated: 2025/11/28 15:16:25 by ahoward          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror -g -I libft -I libft/printf -I .
RM = rm -f
LIBFT = libft/libft.a

NAME = push_swap

SRC =	commands/push.c commands/rev_rotate.c commands/rotate.c commands/swaps.c stack/from_a_to_b.c stack/from_b_to_a.c\
		stack/into_stack.c stack/move_a_to_b.c stack/move_b_to_a.c stack/stack_utils.c errors.c main.c\
		push_swap_utils.c stack/sort.c 


OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L libft -lft


$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re 