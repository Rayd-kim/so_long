/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:58 by youskim           #+#    #+#             */
/*   Updated: 2022/05/10 18:16:14 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_position(int keycode, t_param *param, int	*x, int *y)
{
	if (keycode == KEY_W)
		*y = *y - 1;
	else if (keycode == KEY_A)
		*x = *x - 1;
	else if (keycode == KEY_S)
		*y = *y + 1;
	else if (keycode == KEY_D)
		*x = *x + 1;
	else if (keycode == KEY_ESC)
		exit(0);
	if (param->map[*y][*x] == 'E')
		return (1);
	else if (param->map[*y][*x] == 'C')
	{
		param->elements->c -= 1;
		param->map[*y][*x] = '0';
		return (2);
	}
	else if (param->map[*y][*x] != '1')
		return (3);
	return (0);
}

void	print_count(int *count, t_param *param)
{
	char	*count_itoa;

	*count += 1;
	count_itoa = ft_itoa(*count);
	write (1, count_itoa, ft_strlen(count_itoa));
	write (1, "\n", 1);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 32, 32, 0, count_itoa);
	free (count_itoa);
}

void	key_press2(t_param *param, int x, int y)
{
	param->p_xy[0] = x;
	param->p_xy[1] = y;
	print_map2(param);
}

int	key_press(int keycode, t_param *param)
{
	int			x;
	int			y;
	int			check;
	static int	count = 0;

	x = param->p_xy[0];
	y = param->p_xy[1];
	check = check_position(keycode, param, &x, &y);
	if (check >= 2)
	{
		key_press2(param, x, y);
		print_count(&count, param);
	}
	else if (check == 1)
	{
		print_count(&count, param);
		if (param->elements->c == 0)
			exit(0);
		key_press2(param, x, y);
	}
	return (0);
}

int	program_exit(t_param *param)
{
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(0);
}

void	draw_slime(t_param *param, void *map, void *slime)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = param->mlx_ptr;
	win = param->win_ptr;
	x = param->elements->slime[0];
	y = param->elements->slime[1];
	mlx_put_image_to_window(mlx, win, map, x * 64, y * 64);
	mlx_put_image_to_window(mlx, win, slime, x * 64, y * 64);
}

int	nothing(t_param *param)
{
	static int	k = 1;
	int	t = 1000;

	if (k % (t * 7) == 0)
		draw_slime(param, param->img->map, param->enemy->slime7);
	else if (k % (t * 6) == 0)
		draw_slime(param, param->img->map, param->enemy->slime6);
	else if (k % (t * 5) == 0)
		draw_slime(param, param->img->map, param->enemy->slime5);
	else if (k % (t * 4) == 0)
		draw_slime(param, param->img->map, param->enemy->slime4);
	else if (k % (t * 3) == 0)
		draw_slime(param, param->img->map, param->enemy->slime3);
	else if (k % (t * 2) == 0)
		draw_slime(param, param->img->map, param->enemy->slime2);
	else if (k % (t * 1) == 0)
		draw_slime(param, param->img->map, param->enemy->slime1);
	k++;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_param		*param;

	if (argc != 2)
		error_stdin();
	param = make_param();
	param->elements = make_elements();
	make_map(argv[argc - 1], param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, \
	param->elements->map_w * 64, param->elements->map_h * 64, argv[argc - 1]);
	param->img = open_image(param->mlx_ptr);
	param->enemy = make_enemy(param->mlx_ptr);
	print_map(param);
	mlx_hook(param->win_ptr, 2, 0, &key_press, param);
	mlx_hook(param->win_ptr, 17, 0, &program_exit, param);
	mlx_loop_hook(param->mlx_ptr, &nothing, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
