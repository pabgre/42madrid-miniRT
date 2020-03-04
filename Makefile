# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballest <jballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 15:27:00 by jballest          #+#    #+#              #
#    Updated: 2020/03/04 15:15:58 by jballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBFT = libs/libft/libft.a

#SRC_OLD = mainnotsoold.c 	$(SRC_VECTOR) $(SRC_GEO) $(SRC_MATRIX) $(SRC_RAY) $(SRC_MLX)

SRC = main.c $(SRC_VECTOR) $(SRC_GEO) $(SRC_MATRIX) $(SRC_RAY) $(SRC_MLX) $(SRC_COLOR) $(SRC_POL) $(SRC_CONF)

SRC_VECTOR = srcs/vector/vector_utils_1.c	srcs/vector/vector_utils_2.c

SRC_GEO = srcs/geometry/geometry_utils_0.c srcs/geometry/geometry_utils_1.c srcs/geometry/geometry_utils_2.c srcs/geometry/geometry_utils_3.c srcs/geometry/geometry_utils_4.c

#SRC_MATRIX = srcs/matrix/matrix_utils_1.c srcs/matrix/matrix_utils_2.c

SRC_RAY = srcs/raytracer/raytracer_utils_1.c srcs/raytracer/raytracer_utils_2.c

SRC_MLX = srcs/mlx/mlx_utils1.c

SRC_POL = srcs/polinom/polinom_utils_1.c

SRC_COLOR = srcs/color/color_utils.c

SRC_CONF = srcs/configuration/file_reader_utils.c srcs/configuration/atod.c\
			srcs/configuration/gnl/get_next_line.c


CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#MLX_FLAGS = -L./libs/minilibx_linux -lmlx -lm -L/usr/include/../lib -lXext -lX11 -lbsd

all: $(SRC)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRC) $(LIBFT)

old: $(SRC_OLD)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRC_OLD) $(LIBFT)
