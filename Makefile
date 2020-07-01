# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballest <jballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 15:27:00 by jballest          #+#    #+#              #
#    Updated: 2020/07/01 13:28:31 by jballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

NAME = coolMiniRT

CC = gcc

RM = rm -rf

HEADERS = includes

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ./libs/libft/
LIBFT = -L $(LIBFT_DIR) -lft

CFLAGS = -Wall -Werror -Wextra

ifeq ($(UNAME), Linux)
	MLX_DIR = ./libs/minilibx_linux/
	MLX = -L $(MLX_DIR) -lmlx_Linux
	CFLAGS += -lXext -lX11 -lm -lbsd
endif

ifeq ($(UNAME), Darwin)
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

SRC_CONF =	srcs/configuration/file_reader_utils.c	\
			srcs/configuration/atod.c	\
			srcs/configuration/gnl/get_next_line.c	\
			srcs/configuration/gnl/get_next_line_utils.c	\
# --------------------------------------------------------------------------------

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

#all2: $(SRC)
#	$(CC) $(CFLAGS) $(MLX_FLAGS) main.c $(SRC) $(LIBFT)


all: mlx $(NAME)
	-@$(CC) main.c $(OBJS) -I $(HEADERS) $(LIBFT) $(MLX) $(CFLAGS) -o $(NAME)

debug:
	-@$(CC) -g main_workinglists.c libs/libft/*.c $(SRC) -I $(HEADERS) $(MLX) $(CFLAGS) -o $(NAME)

$(NAME): $(OBJS)
#	-@make bonus -C $(LIBFT_DIR)

%.o: %.c
	-@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

normi: $(SRC)
	#make norminette -C $(LIBFT_DIR)
	norminette $(SRC)

mlx:
	-@make -C $(MLX_DIR) >> /dev/null

mlxclean:
	-@make clean -C $(MLX_DIR)


clean:
	-@$(RM) $(OBJS)
#	-@make cleanall -C $(LIBFT_DIR)

fclean:	clean
#	-@make fclean -C $(LIBFT_DIR)
	-@make clean -C $(MLX_DIR)
	-@$(RM) $(NAME)

re:	fclean all

pwd:
	echo $(PWD)

.PHONY:	all clean fclean re
