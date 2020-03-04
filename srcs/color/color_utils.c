/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:06:27 by jballest          #+#    #+#             */
/*   Updated: 2020/03/03 16:19:12 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

int	ft_rgb_to_int(t_color rgb)
{
	int color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;

	return (color);
}

t_color	init_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;

	return (color);
}

t_color	ft_rgb_shade(t_color rgb, double shade_amount)
{
	t_color color;
	shade_amount = (shade_amount >= 1 ? 1 : shade_amount);
	shade_amount = (shade_amount <= 0 ? 0 : shade_amount);
	color.r = (unsigned char)((double)rgb.r * (1.0 - shade_amount));
	color.g = (unsigned char)((double)rgb.g * (1.0 - shade_amount));
	color.b = (unsigned char)((double)rgb.b * (1.0 - shade_amount));

	return (color);
}

int	ft_rgb_tint(t_color rgb, float tint_amount)
{
	t_color color;

	color.r = rgb.r + (255 - rgb.r) * tint_amount;
	color.g = rgb.g + (255 - rgb.g) * tint_amount;
	color.b = rgb.b + (255 - rgb.b) * tint_amount;

	return (ft_rgb_to_int(color));
}
