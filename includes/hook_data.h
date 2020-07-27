/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:31:09 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 13:35:39 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_DATA_H
# define HOOK_DATA_H
# include "my_mlx.h"
# include "raytracer.h"

typedef struct	s_hook_data{
	t_mlx	*mlx;
	t_scene	*scene;
	t_list	*camera;
}				t_hook_data;

int				pressed_key(int key, t_hook_data *hook_data);
void			ft_paint_pixel(int i, unsigned int color, t_mlx *mlx);
void			ft_init_mlx(t_mlx *mlx);
int				close_mlx(t_mlx *mlx);
void			pan_cam_y(t_hook_data *hook_data, int dir);
void			pan_cam_x(t_hook_data *hook_data, int dir);
void			pan_cam(int key, t_hook_data *hook_data);
void			local_rotation_x(t_hook_data *hook_data, double theta,
											t_vector normal);
void			local_rotation_y(t_hook_data *hook_data, double theta,
											t_vector normal);
void			global_rotation(t_hook_data *hook_data, double theta,
						t_vector normal, int dir);
void			perform_zoom(t_hook_data *hook_data, t_vector normal, int dir);
void			zoom(int key, t_hook_data *hook_data);
void			reset_raytracer(t_hook_data *hook_data);
int				pressed_key(int key, t_hook_data *hook_data);
#endif
