/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:00:41 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/21 13:50:21 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/vector.h"

t_m_plane		pl(t_vector normal, t_vector point)
{
	t_m_plane plane;

	plane.normal = normalize(normal);
	plane.point = point;

	return (plane);
}

t_line		l(t_vector dir, t_vector origin)
{
	t_line line;

	line.dir = normalize(dir);
	line.point = origin;
	return (line);
}


