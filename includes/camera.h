/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:36:34 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 12:04:53 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"

typedef struct	s_screen
{
	t_vector pos;
	t_vector x_axis;
	t_vector y_axis;

	int h;
	int w;
}				t_screen;

typedef struct	s_camera
{
	t_vector pos;

	t_screen display;
	double dist;
}				t_camera;
#endif
