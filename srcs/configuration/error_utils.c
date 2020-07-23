/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:26:15 by npinto-g          #+#    #+#             */
/*   Updated: 2020/07/23 12:31:17 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		conf_error(t_conf conf)
{
	printf("\033[1;31m");
	printf("# ERROR :\n");
	if (!conf.flag.no_f)
	{
		if (!conf.flag.r)
			printf("\tNO RESOLUTION set\n");
		if (!conf.flag.c)
			printf("\tNO CAMERA initialized\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;33m");
		printf("\tNo '.rt' file found\n");
		printf("\033[0m");
	}
	printf("\033[1;33m");
	if (conf.flag.error == 1)
		printf("\t\tCheck your '.rt' file\n");
	printf("\033[0m");
	return (-1);
}
