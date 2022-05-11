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
	else if (param->map[*y][*x] == 'S')
		return (2);
	else if (param->map[*y][*x] == 'C')
	{
		param->elements->c -= 1;
		param->map[*y][*x] = '0';
		return (3);
	}
	else if (param->map[*y][*x] == '0')
		return (3);
	return (0);
}

void	key_press2(t_param *param, int x, int y, int *count)
{
	char	*count_itoa;

	param->p_xy[0] = x;
	param->p_xy[1] = y;
	print_map2(param);
	*count += 1;
	count_itoa = ft_itoa(*count);
	write (1, count_itoa, ft_strlen(count_itoa));
	write (1, "\n", 1);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 32, 32, 0, count_itoa);
	free (count_itoa);
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
	if (param->elements->c == 0)
		param->img->exit = param->img->exit_open;
	if (check == 3)
		key_press2(param, x, y, &count);
	else if (check == 2)
	{
		write (1, "ENEMY ATTACK!!\n", 15);
		write (1, "EXIT FAIL!!\n", 12);
		exit(0);
	}
	else if (check == 1)
	{
		key_press2(param, x, y, &count);
		if (param->elements->c == 0)
		{
			write (1, "EXIT SUCCESS!!\n", 15);
			exit(0);
		}
	}
	return (0);
}

int	program_exit(t_param *param)
{
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(0);
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
	param->elements->slime_x = slime_position(param);
	param->elements->slime_y = slime_position(param);
	print_map(param);
	mlx_hook(param->win_ptr, 2, 0, &key_press, param);
	mlx_hook(param->win_ptr, 17, 0, &program_exit, param);
	mlx_loop_hook(param->mlx_ptr, &nothing, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
