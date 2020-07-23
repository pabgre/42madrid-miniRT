/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:01:53 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 13:30:10 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_READER_H
# define FILE_READER_H
# include "../srcs/configuration/gnl/get_next_line.h"
# include "vector.h"
# include "raytracer.h"

typedef	struct	s_flag
{
	int		save;
	int		r;
	int		c;
	int		error;
	int		no_f;
}				t_flag;

typedef	struct	s_conf
{
	t_scene		my_scene;
	t_camera	my_camera;
	t_mlx		mlx;
	t_flag		flag;
}				t_conf;

t_conf		scene_conf(char *scene);
void		scene_parser(char *buf, t_conf *conf);
void		conf_printer(t_conf conf);
int			nbrlen(long nb);
long double	ft_atod(const char *str);
size_t		declen(double d);
int			is_in_set(const char c, char *set);
double		get_int(char **buf);
double		get_double(char **buf);
void		resolution(char *buf, t_conf *conf);
void		sphere(char *buf, t_conf *conf);
double		v1_param(char **buf);
t_vector	v3_param(char **buf);
t_color		v3_param_color(char **buf);
double		limit(double d, double min, double max);
t_color		color(double r, double g, double b);
t_sphere	*sphere_init(double *param);
t_cylinder	*cylinder_init(double *param);
t_triangle	*triangle_init(double *param);
t_m_plane	*plane_init(double *param);
double		*get_params(const char *buf, int size);
void		cylinder(char *buf, t_conf *conf);
void		sphere(char *buf, t_conf *conf);
void		triangle(char *buf, t_conf *conf);
void		light(char *buf, t_conf *conf);
void		camera(char *buf, t_conf *conf);
void		square(char *buf, t_conf *conf);
#endif
