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

double		limit(double d, double min, double max)
{
	d = (d < min) ? min : d;
	d = (d > max) ? max : d;
	return (d);
}

t_color		color(double r, double g, double b)
{
	t_color		color;


	color.r = limit(r, 0, 255);
	color.g = limit(g, 0, 255);
	color.b = limit(b, 0, 255);
	return (color);
}

//#####INITS######

t_sphere	*sphere_init(double	*param)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	sphere->center = vec(param[0], param[1], param[2]);
	sphere->radius = param[3] / 2;
	sphere->color = color(param[4], param[5], param[6]);
	return (sphere);
}

t_cylinder		*cylinder_init(double *param)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->center = vec(param[0], param[1], param[2]);
	cylinder->dir = normalize(vec(param[3], param[4], param[5]));
	cylinder->radius = param[6] / 2;
	cylinder->height = param[7];
	cylinder->color = color(param[8], param[9], param[10]);
	return (cylinder);
}

t_triangle	*triangle_init(double *param)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	triangle->point_a = vec(param[0], param[1], param[2]);
	triangle->point_b = vec(param[3], param[4], param[5]);
	triangle->point_c = vec(param[6], param[7], param[8]);
	triangle->color = color(param[9], param[10], param[11]);
	return (triangle);
}

t_m_plane	*plane_init(double *param)
{
	t_m_plane *plane;

	plane = malloc(sizeof(t_m_plane));
	plane->point = vec(param[0], param[1], param[2]);
	plane->normal = normalize(vec(param[3], param[4], param[5]));
	plane->color = color(param[6], param[7], param[8]);

	return (plane);
}

//####CORE_FTS####

double		*get_params(const char *buf, int size)
{
	double		*param;
	int			pos;
	int			l;

	pos = 0;
	l = 0;
	param = (double *)malloc(sizeof(double) * size);
	while (buf[pos])
	{
		if ((ft_isdigit(buf[pos]) || buf[pos] == '-') && l < size)
		{
			param[l] = ft_atod(&buf[pos]);
			l++;
			while((buf[pos])!= 32 && buf[pos] != ',' && buf[pos])
				pos++;
		}
		pos++;
	}
	return (param);
}

char		*rm_spaces(char *buf)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup(buf);
	while(aux[i] != '\0')
	{
		if (aux[i] != 32)
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
	i = (ft_isdigit(**s_param)) ? 0 : 1;
	j = 0;
	len = str_array_len(s_param);
	param = malloc(sizeof(param) * len);
	while (i < len)
	{
		param[j] = ft_atod(s_param[i]);
		i++;
		j++;
	}
	return (param);
}

int ft_mcd(int a, int b){
	int c;

	c = 1;

	while (b != 0){
		c = b;
		b = a % b;
		a = c;
	}
	return (c);
}


void		camera(char *buf, t_conf *conf)
{
	t_screen my_screen;
	t_camera *my_camera;
	double	*param;
	int mcd;
	double angle;

	conf->flag.c = 1;
	my_camera = malloc(sizeof(t_camera));
	param = get_params(buf, 7);
	mcd = ft_mcd(conf->mlx.window_size.x, conf->mlx.window_size.y);
	my_screen.w = conf->mlx.window_size.x / mcd;
	my_screen.h = conf->mlx.window_size.y / mcd;
	angle = limit(param[6], 0, 180);
	angle *= 3.14 / 360.0;
	my_camera->dist = (my_screen.w / 2.0) / tan(angle);
	my_screen.x_axis = normalize(cross_prod(
						vec(param[3], param[4], param[5]), vec(0, 0, -1)));
	my_screen.y_axis = normalize(vec(0, 0, -1));
	my_screen.pos = vec(param[0], param[1], param[2]);
	my_camera->pos = add(prod(normalize(vec(param[3], param[4], param[5])),
				-my_camera->dist), my_screen.pos);
	free(param);
	my_camera->display = my_screen;
	ft_lstadd_front(&(conf->my_scene.cam_lst), ft_lstnew(my_camera));
}

void	resolution(char *buf, t_conf *conf)
{
	double		*param;

	param = get_params(buf, 2);
	conf->mlx.window_size.x = limit(param[0], 1, 2560);
	conf->mlx.window_size.y = limit(param[1], 1, 1440);
	conf->flag.r = 1;
	free(param);
}

void	light(char *buf, t_conf *conf)
{
	t_light 	*current_light;
	double		*param;

	current_light = malloc(sizeof(t_light));
	param = get_params(buf, 7);
	current_light->pos = vec(param[0], param[1], param[2]);
	current_light->radius = limit(param[3], 0, 1);
	current_light->color = color(param[4], param[5], param[6]);
	free(param);
	ft_lstadd_front(&(conf->my_scene.light_lst), ft_lstnew(current_light));
}



void		sphere(char *buf, t_conf *conf)
{
	t_3d_obj 	*obj;
	double		*param;

	param = get_params(buf, 7);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = SPHERE;
	obj->obj = sphere_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}



void		cylinder(char *buf, t_conf *conf)
{
	t_3d_obj 	*obj;
	double		*param;


	param = get_params(buf, 11);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = CYLINDER;
	obj->obj = cylinder_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}


void		square(char *buf, t_conf *conf)
{
	t_3d_obj 	*obj;
	double		*param;
	t_vector	v;
	t_vector	w;
	t_triangle *tr;

	param = get_params(buf, 10);
	v = normalize(vec(param[5], 0, -param[3]));
	w = normalize(cross_prod(v, vec(param[3], param[4], param[5])));
	v =  prod(v, param[6] * sqrt(2)/2);
	w =  prod(w, param[6] * sqrt(2)/2);


	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	tr = malloc(sizeof(t_triangle));
	tr->point_a = add(vec(param[0], param[1], param[2]), v);
	tr->point_b = add(vec(param[0], param[1], param[2]), w);
	tr->point_c = subs(vec(param[0], param[1], param[2]), v);
	tr->color = init_rgb(param[7], param[8], param[9]);
	obj->obj = tr;
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	tr = malloc(sizeof(t_triangle));
	tr->point_a = subs(vec(param[0], param[1], param[2]), v);
	tr->point_b = subs(vec(param[0], param[1], param[2]), w);
	tr->point_c = add(vec(param[0], param[1], param[2]), v);
	tr->color = init_rgb(param[7], param[8], param[9]);
	obj->obj = tr;
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
	free(param);
}


void		triangle(char *buf, t_conf *conf)
{
	t_3d_obj 	*obj;
	double		*param;

	param = get_params(buf, 12);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = TRIANGLE;
	obj->obj = triangle_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

void		ambient(char *buf, t_conf *conf){
	double *param;

	param = get_params(buf, 4);
	conf->my_scene.ambient.radius = param[0];
	conf->my_scene.ambient.color = color(param[1], param[2], param[3]);
	free(param);
}


void		plane(char *buf, t_conf *conf)
{
	t_3d_obj	*obj;
	double		*param;

	param = get_params(buf, 9);
	obj = malloc(sizeof(t_3d_obj));
	obj->type = PLANE;
	obj->obj = plane_init(param);
	free(param);
	ft_lstadd_front(&(conf->my_scene.obj_lst), ft_lstnew(obj));
}

void		scene_parser(char *buf, t_conf *conf)
{
	if (*buf == 'R')
		resolution(buf, conf);
	else if (*buf == 'A')
		ambient(buf, conf);
	else if (*buf == 'l')
		light(buf, conf);
	else if (*buf == 's'){
		buf++;
		if (*buf == 'p')
			sphere(buf, conf);
		else if (*buf == 'q')
			square(buf, conf);
	}
	else if (*buf == 'c')
	{
		buf++;
		if (*buf == 'y')
			cylinder(buf, conf);
		else if (*buf != 'y' && conf->flag.r)
			camera(buf, conf);
	}
	else if (*buf == 'p')
		plane (buf, conf);
	else if (*buf == 't')
		triangle(buf, conf);
	else
		conf->flag.error = 1;
}

int		setfile(char **file, char *buf, int i)
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

t_conf		scene_conf(char *scene)
{
	t_conf	conf;
	int		fd;
	char	*buf;
	char	*file[42];
	int		i;

	i = 1;
	fd = open(scene, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &buf))
		{
			if (is_in_set(*buf, "R A c l sp pl sq cy tr"))
				i += setfile(file, buf, i);
			free(buf);
		}
		i = 0;
		while(file[i])
		{
			scene_parser(file[i], &conf);
			free(file[i]);
			i++;
		}
		free(buf);
		close(fd);
	}
	else
		conf.flag.no_f = 1;
	return (conf);
}