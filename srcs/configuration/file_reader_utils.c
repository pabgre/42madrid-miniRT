#include "minirt.h"

int		is_in_set(const char c, char* set)
{
	while (*set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}

double	get_int(char **buf)
{
	double	n;

	n = 0;
	while(**buf != '\0')
	{
		if (ft_isdigit(**buf) || **buf == '-')
		{
			n = ft_atoi(*buf);
			break ;
		}
		*buf += 1;
	}
	return (n);
}

double	get_double(char **buf)
{
	double	n;

	n = 0;
	while(**buf != '\0')
	{
		if (ft_isdigit(**buf) || **buf == '-')
		{
			n = ft_atod(*buf);
			break ;
		}
		*buf+= 1;
	}
	return (n);
}

int		nbrlen(long nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

//####CORE_FTS####

double		v1_param(char **buf)
{
	double	param;

	param = get_double(buf);
	*buf += declen(param);
	return (param);
}

t_vector	v3_param(char **buf)
{
	double		x;
	double		y;
	double		z;
	t_vector	param;

	x = get_double(buf);
	*buf += declen(x);
	y = get_double(buf);
	*buf += declen(y);
	z = get_double(buf);
	*buf += declen(z);
	param = vec(x, y, z);
	return (param);
}

t_color		color(double r, double g, double b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

char		*rm_spaces(char *buf)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup(buf);
	while(aux[i] != '\0')
	{
		if (ft_isspace(aux[i]))
		{
			aux[i] = ',';
		}
		i++;
	}
	return (aux);
}

size_t		str_array_len(char **array)
{
	size_t		i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	return (i);
}

size_t		array_len(double *array, size_t size)
{
	size_t		i;

	array = NULL;
	i = size / sizeof(array[0]);
	return (i);
}

double			*get_params_array(char **s_param)
{
	double		*param;
	size_t		i;
	size_t		j;
	size_t		len;
	//printf("SIZE SIZE = %zu\n", i = sizeof(param));
	i = (ft_isdigit(**s_param)) ? 0 : 1;
	j = 0;
	len = str_array_len(s_param);
	param = malloc(sizeof(param) * len);
	while (i < len)
	{
		param[j] = ft_atod(s_param[i]);
		printf("converting : %s \n", s_param[i]);
		printf("converted : %f \n", param[j]);
		i++;
		j++;
		/*if (i == 5)
		{
			break ;
		}*/
	}
	return (param);
}

void		camera(char *buf, t_conf *conf)
{
	t_screen my_screen;

	conf->my_camera.pos = v3_param(&buf);
	conf->my_camera.dist = 5;
	my_screen.h = 9;
	my_screen.w = 16;
	my_screen.x_axis = normalize(vec(0, -1, 0));
	my_screen.y_axis = normalize(vec(0, 0, 1));
	my_screen.pos = add(prod(normalize(cross_prod
				(my_screen.x_axis, my_screen.y_axis)),
				conf->my_camera.dist), conf->my_camera.pos);
	conf->my_camera.display = my_screen;
}

void	resolution(char *buf, t_conf *conf)
{
	float		x;
	float		y;
	//char		*res;
	//char		**s_param;
	double		*param;

	//res = rm_spaces(buf);
	//s_param = ft_split(res, ',');
	param = get_params_array(ft_split(rm_spaces(buf), ','));
	x = param[0];
	y = param[1];
	conf->mlx.window_size.x = (x > 2560) ? 2560 : x;
	conf->mlx.window_size.y = (y > 1440) ? 1440 : y;

}

void	light(char *buf, t_conf *conf)
{
	t_light 	*current_light;
	char		*light;
	char		**s_param;
	double		*param;

	current_light = malloc(sizeof(t_light));
	light = rm_spaces(buf);
	s_param = ft_split(light, ',');
	param = get_params_array(s_param);
	current_light->pos = vec(param[0], param[1], param[2]);
	current_light->radius = param[3];
	current_light->color = color(param[4], param[5], param[6]);

	ft_lstadd_front(&(conf->my_scene.light_lst), ft_lstnew(current_light));
}



void		sphere(char *buf, t_conf *conf)
{
	t_sphere 	*my_sphere;
	t_3d_obj 	*obj;
	double		*param;

	param = get_params_array(ft_split(rm_spaces(buf), ','));
	obj = malloc(sizeof(t_3d_obj));
	obj->type = SPHERE;
	my_sphere = malloc(sizeof(t_sphere));
	my_sphere->center = vec(param[0], param[1], param[2]);
	my_sphere->radius = param[3] / 2;
	my_sphere->color = color(param[4], param[5], param[6]);
	obj->obj = my_sphere;
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

void		cylinder(char *buf, t_conf *conf)
{
	t_cylinder 	*my_cylinder;
	t_3d_obj 	*obj;
	double		*param;

	param = get_params_array(ft_split(rm_spaces(buf), ','));
	obj = malloc(sizeof(t_3d_obj));
	obj->type = CYLINDER;
	my_cylinder = malloc(sizeof(t_cylinder));
	my_cylinder->center = vec(param[0], param[1], param[2]);
	my_cylinder->dir = normalize(vec(param[3], param[4], param[5]));
	my_cylinder->radius = param[6] / 2;
	my_cylinder->height = param[7];
	my_cylinder->color = color(param[8], param[9], param[10]);
	obj->obj = my_cylinder;
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

void		triangle(char *buf, t_conf *conf)
{
	t_triangle 	*my_triangle;
	t_3d_obj 	*obj;
	char		*triangle;
	char		**s_param;
	double		*param;

	triangle = rm_spaces(buf);
	s_param = ft_split(triangle, ',');
	param = get_params_array(s_param);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	my_triangle = malloc(sizeof(t_triangle));
	my_triangle->point_a = vec(param[0], param[1], param[2]);
	my_triangle->point_b = vec(param[3], param[4], param[5]);
	my_triangle->point_c = vec(param[6], param[7], param[8]);
	my_triangle->color = color(param[9], param[10], param[11]);
	obj->obj = my_triangle;
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

void		scene_parser(char *buf, t_conf *conf)
{
	if (*buf == 'R')
	{
		resolution(buf, conf);
		conf->flag.r = 1;
	}
	/*if (*buf == 'A')
		ambient(buf, conf)*/
	else if (*buf == 'l')
		light(buf, conf);
	else if (*buf == 's' && (++buf && *buf == 'p'))
		sphere(buf, conf);
	else if (*buf == 'c')
	{
		buf++;
		if (*buf == 'y')
			cylinder(buf, conf);
		else if (*buf != 'y' && conf->flag.r)
			camera(buf, conf);
	}
	else if (*buf == 't')
		triangle(buf, conf);
}

t_conf		scene_conf(char *scene)
{
	t_conf	conf;
	int		fd;
	char	*buf;
	char	*set;

	set = ft_strdup("R A c l sp pl sq cy tr");
	fd = open(scene, O_RDONLY);
	while (get_next_line(fd, &buf))
	{
		if (is_in_set(*buf, set))
		{
			scene_parser(buf, &conf);
		}
		free(buf);
	}
	free(buf);
	free(set);
	close(fd);
	return (conf);
}
