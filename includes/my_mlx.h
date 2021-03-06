/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:20:08 by jballest          #+#    #+#             */
/*   Updated: 2020/07/08 11:56:38 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "vector.h"

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*img_ptr;

	char		*window_title;
	t_vector	window_size;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

void	ft_init_mlx(t_mlx *mlx);
void	ft_paint_pixel(int i, unsigned int color, t_mlx *mlx);
int		close_mlx(t_mlx *mlx);

#endif
