# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 18:08:12 by thde-sou          #+#    #+#              #
#    Updated: 2025/08/30 21:44:13 by thde-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = so_long.a

EXEC = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = so_long.c assemble_map.c error.c check_map.c check_map_utils.c map_error.c check_map_extra.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	ar rcsT $(NAME) $(OBJ) $(LIBFT)
	$(CC) $(NAME) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(EXEC) $(MARKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re leak
