/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:03:12 by jballest          #+#    #+#             */
/*   Updated: 2020/02/17 17:31:58 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

//# include "libs/minilibx_macos/mlx.h"
# include "libs/minilibx_linux/mlx.h"
# include "includes/vector.h"
# include "includes/camera.h"
# include "includes/matrix.h"
# include "includes/geometry.h"
# include "includes/raytracer.h"
# include "includes/libft.h"

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*img_ptr;
}				t_mlx;

typedef struct	s_mlx_data
{
	char		*window_title;
	t_vector	window_size;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx_data;

t_mlx	ft_init_mlx(t_mlx_data *data);

#endif
