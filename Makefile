# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 18:08:12 by thde-sou          #+#    #+#              #
#    Updated: 2025/09/11 20:26:11 by thde-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = so_long.a

EXEC = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRC = so_long.c src/map/assemble_map.c src/error.c src/map/check_map.c \
src/map/check_map_utils.c src/map/map_error.c src/map/check_map_extra.c \
src/render/open_window.c src/render/render_utils.c src/utils.c src/events/move.c \
src/events/events_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MLX_DIR) $(EXEC)

$(MLX_DIR):
	git clone https://github.com/42paris/minilibx-linux.git
	$(MAKE) -C $(MLX_DIR) all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(EXEC): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LIBFT) $(LIBS) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) 
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(EXEC)
	rm -rf $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
