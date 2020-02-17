/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:03:12 by jballest          #+#    #+#             */
/*   Updated: 2020/02/17 14:23:03 by psan-gre         ###   ########.fr       */
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

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*img_ptr;
}				t_mlx;

#endif
