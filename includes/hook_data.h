#ifndef HOOK_DATA_H
# define HOOK_DATA_H
# include "my_mlx.h"
# include "raytracer.h"

typedef struct	s_hook_data{
	t_mlx	*mlx;
	t_scene *scene;
	t_list *camera;
}				t_hook_data;

int		pressed_key(int key, t_hook_data *hook_data);

#endif
