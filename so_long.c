#include "so_long.h"

t_image	*open_image(void *mlx_ptr)
{
	t_image	*img;
	
	img = (t_image *)malloc(sizeof(t_image));
	if (img == 0)
		exit (1);
	ft_memset(img, 0, sizeof(t_image));
	img->map = mlx_xpm_file_to_image(mlx_ptr, "./Texture/map.xpm", &img->x, &img->y);
	img->wall = mlx_xpm_file_to_image(mlx_ptr, "./Texture/wall.xpm", &img->x, &img->y);
	img->exit = mlx_xpm_file_to_image(mlx_ptr, "./Texture/exit_close.xpm", &img->x, &img->y);
	img->goal = mlx_xpm_file_to_image(mlx_ptr, "./Texture/box.xpm", &img->x, &img->y);
	img->player = mlx_xpm_file_to_image(mlx_ptr, "./Texture/Player.xpm", &img->x, &img->y);
	return (img);
}

void	print_map(t_param *param)
{
	int		i;
	int		k;

	i = 0;
	while (i < param->elements->map_W)
	{
		k = 0;
		while (k < param->elements->map_H)
		{
			mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->map, i * 64, k * 64);
			k++;
		}
		i++;
	}
	i = 0;
	while (param->map[i])
	{
		k = 0;
		while (param->map[i][k])
		{
			if (param->map[i][k] == '1')
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->wall, k * 64, i * 64);
			else if (param->map[i][k] == 'E')
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->exit, k * 64, i * 64);
			else if (param->map[i][k] == 'C')
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->goal, k * 64, i * 64);
			else if (param->map[i][k] == 'P')
			{
				param->P_XY[0] = k;
				param->P_XY[1] = i;
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->player, param->P_XY[0] * 64, \
				param->P_XY[1] * 64);
			}
			k++;
		}
		i++;
	}
}

void	print_map2(t_param *param)
{
	int		i;
	int		k;

	i = 0;
	while (i < param->elements->map_W)
	{
		k = 0;
		while (k < param->elements->map_H)
		{
			mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->map, i * 64, k * 64);
			k++;
		}
		i++;
	}
	i = 0;
	while (param->map[i])
	{
		k = 0;
		while (param->map[i][k])
		{
			if (param->map[i][k] == '1')
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->wall, k * 64, i * 64);
			else if (param->map[i][k] == 'E')
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->exit, k * 64, i * 64);
			else if (param->map[i][k] == 'C')
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->goal, k * 64, i * 64);
			else if (param->map[i][k] == 'P')
			{
				//param->P_XY[0] = k;
				//param->P_XY[1] = i;
				mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->player, param->P_XY[0] * 64, \
				param->P_XY[1] * 64);
			}
			k++;
		}
		i++;
	}
}

int	check_position(int keycode, t_param *param, int	*x, int *y)
{
	if (keycode == key_w)
		*y = *y - 1;
	else if (keycode == key_a)
		*x = *x - 1;
	else if (keycode == key_s)
		*y = *y + 1;
	else if (keycode == key_d)
		*x = *x + 1;
	else if (keycode == key_esc)
		exit(0);
	if (param->map[*y][*x] == 'E')
		return (1);
	else if (param->map[*y][*x] == 'C')
	{
		param->elements->C -= 1;
		param->map[*y][*x] = '0';
		return (2);
	}
	else if (param->map[*y][*x] != '1')
		return (3);
	return (0);
}

int	key_press(int keycode, t_param *param)
{
	int	x;
	int	y;
	int	check;

	x = param->P_XY[0];
	y = param->P_XY[1];
	check = check_position(keycode, param, &x, &y);
	if (check >= 2)
	{
		param->P_XY[0] = x;
		param->P_XY[1] = y;
		print_map2(param);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->player, x * 64, y * 64);
	}
	else if (check == 1)
	{
		if (param->elements->C == 0)
			exit(0);
		param->P_XY[0] = x;
		param->P_XY[1] = y;
		print_map2(param);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->player, x * 64, y * 64);
	}
	return (0);
}

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_elements	*elements;
	char		**map;
	int			fd;
	t_param		*param;

	elements = (t_elements *)malloc(sizeof(t_elements));
	if (elements == 0)
		exit(1);
	ft_memset(elements, 0, sizeof(t_elements));
	fd = open ("./map1.ber", O_RDONLY);
	if (fd < 0)
		exit (1);
	map = check_map(fd, elements);
	close(fd);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, elements->map_W * 64, elements->map_H * 64, "title");

	param = (t_param *)malloc(sizeof(t_param));
	if (param == 0)
		exit (1);
	param->elements = elements;
	param->map = map;
	param->win_ptr = win_ptr;
	param->mlx_ptr = mlx_ptr;
	param->img = open_image(mlx_ptr);

	print_map(param);
	mlx_hook(win_ptr, 3, 0, &key_press, param);
	mlx_loop(mlx_ptr);
	return (0);
}