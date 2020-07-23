# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 15:27:00 by jballest          #+#    #+#              #
#    Updated: 2020/07/23 12:25:23 by psan-gre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

NAME = coolMiniRT

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

INCLUDES = -I ./includes

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ./libs/libft/
LIBFT = -L $(LIBFT_DIR) -lft

CFLAGS = -Wall -Werror -Wextra

ifeq ($(UNAME), Linux)
	NORMINETTE = ~/.norminette/norminette.rb
	MLX_DIR = ./libs/minilibx_linux/
	MLX = -L $(MLX_DIR) -lmlx_Linux
	CFLAGS += -lXext -lX11 -lm -lbsd
endif

ifeq ($(UNAME), Darwin)
	NORMINETTE = norminette
	MLX_DIR = ./libs/minilibx_macos/
	MLX = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#	MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# SOURCES -----------------------------------------------------------------------

SRC = $(SRC_VECTOR) $(SRC_GEO) $(SRC_MATRIX) $(SRC_RAY) $(SRC_MLX) $(SRC_COLOR) $(SRC_POL) $(SRC_CONF)

SRC_VECTOR =	srcs/vector/vector_utils_1.c	\
				srcs/vector/vector_utils_2.c	\

SRC_GEO =	srcs/geometry/geometry_utils_0.c	\
			srcs/geometry/geometry_utils_1.c	\
			srcs/geometry/geometry_utils_2.c	\
			srcs/geometry/geometry_utils_3.c	\
			srcs/geometry/geometry_utils_4.c	\

SRC_RAY =	srcs/raytracer/raytracer_utils_1.c	\
			srcs/raytracer/raytracer_utils_2.c	\

SRC_MLX = srcs/mlx/mlx_utils1.c	\

SRC_POL = srcs/polinom/polinom_utils_1.c	\

SRC_COLOR = srcs/color/color_utils.c	\
			srcs/color/color_utils2.c

SRC_CONF =				srcs/configuration/atod.c	\
			srcs/configuration/gnl/get_next_line.c	\
			srcs/configuration/file_reader_utils.c	\
			srcs/configuration/error_utils.c \
# --------------------------------------------------------------------------------

all: $(NAME)
	-@$(CC) main.c $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) $(CFLAGS) -o $(NAME)

debug: mlx
	$(RM) coolMiniRTDebug
	-@$(CC) -g main.c $(SRC) $(INCLUDES) $(LIBFT_DIR)*.c $(MLX) $(CFLAGS) -o $(NAME)Debug

test: all
	./coolMiniRT

$(NAME): $(OBJS)
	-@make bonus -C $(LIBFT_DIR)

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

normi: $(SRC)
	-@make normi -C $(LIBFT_DIR)
	-@$(NORMINETTE) $(SRC)

mlx:
	-@make -C $(MLX_DIR) $(SILENCE_ALL)


mlxclean:
	-@make clean -C $(MLX_DIR)


clean:
	-@make bclean -C $(LIBFT_DIR)
	-@$(RM) $(OBJS)

fclean:	clean
	-@make fclean -C $(LIBFT_DIR)

	-@make clean -C $(MLX_DIR)

	-@$(RM) $(NAME)

re:	fclean all test

.PHONY:	all clean fclean re
