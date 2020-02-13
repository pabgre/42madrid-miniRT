/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:36:34 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/11 20:18:17 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
#include "Vector/vector.h"
typedef struct s_screen
{
	vector pos;
	vector x_axis;
	vector y_axis;

	int h;
	int w;
}				screen;

typedef struct s_camera
{
	vector pos;

	screen display;
	double fov;
}				camera;
#endif
