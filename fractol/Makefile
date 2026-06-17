# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoward <ahoward@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 13:17:09 by ahoward           #+#    #+#              #
#    Updated: 2026/01/07 15:28:34 by ahoward          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I libft -I libft/printf -I .
RM = rm -f
LIBFT = libft/libft.a
MLX_DIR = mlx-linux
MLX_REPO = https://github.com/42paris/minilibx-linux.git
MLX = $(MLX_DIR)/libmlx_Linux.a

NAME = fractol

SRC = fractol.c fractol_utils.c rendering/render_mb.c rendering/render_js.c rendering/render_utils.c \
		hooks/keys.c hooks/mouse.c

OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(MLX_DIR):
	@test -d $(MLX_DIR) || git clone $(MLX_REPO) $(MLX_DIR)

$(MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR) all


$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME) -L libft -lft


$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean:
	$(RM) $(OBJS) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re $(MLX_DIR) $(MLX) $(LIBFT)
