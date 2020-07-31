/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:26:15 by npinto-g          #+#    #+#             */
/*   Updated: 2020/07/31 10:30:37 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		conf_error(t_conf conf)
{
	ft_putstr_fd("\033[1;31m", 1);
	ft_putstr_fd("# ERROR :\n", 1);
	if (!conf.flag.no_f)
	{
		if (!conf.flag.r)
			ft_putstr_fd("\tNO RESOLUTION set\n", 1);
		if (!conf.flag.c)
			ft_putstr_fd("\tNO CAMERA initialized\n", 1);
		ft_putstr_fd("\033[0m", 1);
	}
	else
	{
		ft_putstr_fd("\033[1;33m", 1);
		ft_putstr_fd("\tNo '.rt' file found\n", 1);
		ft_putstr_fd("\033[0m", 1);
	}
	ft_putstr_fd("\033[1;33m", 1);
	if (conf.flag.error == 1)
		ft_putstr_fd("\t\tCheck your '.rt' file\n", 1);
	ft_putstr_fd("\033[0m", 1);
	return (-1);
}
