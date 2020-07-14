/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:26:15 by npinto-g          #+#    #+#             */
/*   Updated: 2020/07/14 12:22:58 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_error(t_conf conf)
{
	printf("\033[1;31m");
	printf("# ERROR :\n");
	if (!conf.flag.c)
	{
		printf("\tNO CAMERA set\n");
	}
	if (!conf.flag.r)
	{
		printf("\tNO RESOLUTION set\n");
	}
	printf("\033[0m");
	printf("\033[1;33m");
	if (conf.flag.error == 1)
	{
		printf("\t\tCheck your '.rt' file\n");
	}
	else
	{
		printf("\t\tUNKNOWN SOURCE\n");
	}
	printf("\033[0m");
	return (-1);
}