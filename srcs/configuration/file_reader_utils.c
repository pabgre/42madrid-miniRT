#include "../../minirt.h"

int		is_in_set(const char c, char* set)
{
	while (set++)
	{
		if (ft_isspace(*set))
			;
		else
		{
			if (*set == c)
				return (c);
		}
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

void	conf_printer(t_conf conf)
{
	printf("R : x = %f y = %f \n", conf.mlx.window_size.x, conf.mlx.window_size.y);
	printf("c : pos x = %f pos y = %f pos z %f\n", conf.my_camera.pos.x, conf.my_camera.pos.y, conf.my_camera.pos.z);
	printf("sp : pos = %f,%f,%f diameter = %f RGB = %d,%d,%d\n", conf.my_scene.my_sphere.center.x, conf.my_scene.my_sphere.center.y, conf.my_scene.my_sphere.center.z, conf.my_scene.my_sphere.radius, conf.my_scene.my_sphere.color.r, conf.my_scene.my_sphere.color.g,
	conf.my_scene.my_sphere.color.b);
}

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

	printf("\t0 sub-buf = %s \n", *buf);
	x = get_double(buf);
	*buf += declen(x);
	printf("\t1 sub-buf = %s \n", *buf);
	y = get_double(buf);
	*buf += declen(y);
	printf("\t2 sub-buf = %s \n", *buf);
	z = get_double(buf);
	*buf += declen(z);
	param = vec(x, y, z);
	return (param);
}

t_color		v3_param_color(char **buf)
{
	int			r;
	int			g;
	int			b;
	t_color		color;

	r = get_int(buf);
	*buf += nbrlen(r);
	g = get_int(buf);
	*buf +=  nbrlen(g);
	b = get_int(buf);
	*buf += nbrlen(b);
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
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
	float	x;
	float	y;

	x = get_int(&buf);
	buf += nbrlen(x);
	y = get_int(&buf);
	conf->mlx.window_size.x = (x > 2560) ? 2560 : x;
	conf->mlx.window_size.y = (y > 1440) ? 1440 : y;
	
}

void	light(char *buf, t_conf *conf)
{
	conf->my_scene.my_light.pos = v3_param(&buf);
	conf->my_scene.my_light.radius = v1_param(&buf);
	conf->my_scene.my_light.color = v3_param_color(&buf);
}

void		sphere(char *buf, t_conf *conf)
{

	conf->my_scene.my_sphere.center = v3_param(&buf);
	printf("1 buf = %s \n", buf);
	conf->my_scene.my_sphere.radius = v1_param(&buf) / 2;
	printf("2 buf = %s \n", buf);
	conf->my_scene.my_sphere.color = v3_param_color(&buf);
	printf("3 buf = %s \n", buf);
}

void		cylinder(char *buf, t_conf *conf)
{
	conf->my_scene.my_cylinder.center = v3_param(&buf);
	conf->my_scene.my_cylinder.dir = normalize(v3_param(&buf));
	conf->my_scene.my_cylinder.radius = v1_param(&buf) / 2;
	conf->my_scene.my_cylinder.height = v1_param(&buf) / 2;
	conf->my_scene.my_cylinder.color = v3_param_color(&buf);	
}

void		triangle(char *buf, t_conf *conf)
{
	conf->my_scene.my_triangle.point_a = v3_param(&buf);
	conf->my_scene.my_triangle.point_b = v3_param(&buf);
	conf->my_scene.my_triangle.point_c = v3_param(&buf);
	conf->my_scene.my_triangle.color = v3_param_color(&buf);
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

	set = strdup("R A c l sp pl sq cy tr");
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