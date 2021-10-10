# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harsenal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 23:29:41 by harsenal          #+#    #+#              #
#    Updated: 2021/10/06 23:29:44 by harsenal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -O3
LIBRARIES_MAC = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
LIBRARIES_UBUNTU = -lm -lft -L$(LIBFT_DIRECTORY) -L /usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

HEADERS = -I $(INCLUDES_DIRECTORY)
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/

INCLUDES_DIRECTORY = includes/
INCLUDES_LIST = fdf.h

SRC_DIRECTORY = src/
SRC_LIST = main.c \
		   bresenham.c \
		   bresenham_utils.c \
		   color.c \
		   ft_atoi_base_m.c \
		   ft_substr_m.c \
		   read_map.c \
		   read_map_utils.c \
		   shift.c \
		   utils_fdf.c \
		   zoom.c \

	
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))

MINILIBX_DIRECTORY = /usr/local/lib/

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBRARIES_MAC) $(HEADERS)
	@echo "\n$(NAME): $(GREEN)Создание исполняемого файла$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) Готово$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Создание $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) было удалено$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) было удалено$(RESET)"


re: fclean all
