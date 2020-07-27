/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:38:53 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 12:03:31 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;

t_color			init_rgb(unsigned char r, unsigned char g, unsigned char b);
int				ft_rgb_to_int(t_color rgb);
t_color			ft_rgb_shade(t_color rgb, double shade_amount);
t_color			ft_rgb_tint(t_color rgb, float tint_amount);
t_color			ft_rgb_sum(t_color rgb1, t_color rgb2);
t_color			ft_rgb_sum(t_color rgb1, t_color rgb2);
t_color			ft_color_multiply(t_color rgb1, t_color rgb2);
t_color			ft_color_addition(t_color rgb1, t_color rgb2);
t_color			ft_color_dodge(t_color rgb1, t_color rgb2);
t_color			ft_color_screen(t_color rgb1, t_color rgb2);
t_color			ft_color_lighten(t_color rgb1, t_color rgb2);
t_color			ft_color_merge(t_color rgb1, t_color rgb2);
t_color			ft_color_overlay(t_color rgb1, t_color rgb2);
t_color			ft_color_hardlight(t_color rgb1, t_color rgb2);
t_color			ft_color_soflight(t_color rgb1, t_color rgb2);
t_color			ft_color_layer_opacity(t_color rgb, double alpha);
void			ft_rgb_normalize(t_color *rgb);

#endif
