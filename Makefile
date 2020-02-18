# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 15:27:00 by jballest          #+#    #+#              #
#    Updated: 2020/02/18 18:39:56 by psan-gre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBFT = libs/libft/libft.a

SRC_OLD = mainnotsoold.c $(SRC_VECTOR) $(SRC_GEO) $(SRC_MATRIX) $(SRC_RAY) $(SRC_MLX)

SRC = main.c $(SRC_VECTOR) $(SRC_GEO) $(SRC_MATRIX) $(SRC_RAY) $(SRC_MLX) $(SRC_POL)

SRC_VECTOR = srcs/vector/vector_utils_1.c	srcs/vector/vector_utils_2.c	\

SRC_GEO = srcs/geometry/geometry_utils_1.c	srcs/geometry/geometry_utils_2.c srcs/geometry/geometry_utils_3.c

SRC_MATRIX = srcs/matrix/matrix_utils_1.c srcs/matrix/matrix_utils_2.c

SRC_RAY = srcs/raytracer/raytracer_utils_1.c srcs/raytracer/raytracer_utils_2.c

SRC_MLX = srcs/mlx/mlx_utils1.c

SRC_POL = srcs/polinom/polinom_utils_1.c

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#MLX_FLAGS = -L./libs/minilibx_linux -lmlx -lm -L/usr/include/../lib -lXext -lX11 -lbsd

all: $(SRC)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRC) $(LIBFT)

old: $(SRC_OLD)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRC_OLD) $(LIBFT)
