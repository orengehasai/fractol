# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stonegaw <stonegaw@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 21:11:03 by stonegaw          #+#    #+#              #
#    Updated: 2025/12/23 21:11:05 by stonegaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math

CPPFLAGS = -I includes -I minilibx-linux -I /usr/include

SRC =./src/events.c \
	./src/events2.c \
	./src/fractol.c \
	./src/init.c \
	./src/main.c \
	./src/render.c \
	./src/utils.c

OBJ = $(SRC:%.c=%.o)

MLX_DIR = ./minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

MLX_LIB_PATH = $(MLX_DIR)/libmlx.a

.PHONY:all clean fclean re
all:$(NAME)

$(NAME):$(OBJ) $(MLX_LIB_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB_PATH):
	make -C $(MLX_DIR)

./src/%.o: ./src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	make -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all
