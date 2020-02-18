/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:38:53 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 19:20:19 by jballest         ###   ########.fr       */
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

int	ft_rgb_to_int(t_color rgb);
int ft_rgb_shade(t_color rgb, float shade_amount);
int	ft_rgb_tint(t_color rgb, float tint_amount);

#endif
