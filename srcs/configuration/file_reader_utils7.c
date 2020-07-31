/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_utils7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:09:31 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 10:36:05 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			setfile(char **file, char *buf, int i)
{
	if (is_in_set(*buf, "R"))
	{
		file[0] = ft_strdup(buf);
		return (0);
	}
	else
	{
		file[i] = ft_strdup(buf);
		return (1);
	}
}

t_conf		scene_conf(int fd, int i)
{
	t_conf	conf;
	char	*buf;
	char	*file[42];

	if (fd != -1)
	{
		while (get_next_line(fd, &buf))
		{
			if (is_in_set(*buf, "R A c l sp pl sq cy tr"))
				i += setfile(file, buf, i);
			free(buf);
		}
		i = 0;
		while (file[i++])
		{
			scene_parser(file[i - 1], &conf);
			free(file[i - 1]);
		}
		free(buf);
		close(fd);
	}
	else
		conf.flag.no_f = 1;
	return (conf);
}
