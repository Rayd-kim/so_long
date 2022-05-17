/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:58 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:14:43 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (param->map[*y][*x] == '0' && (*x != param->p_xy[0] \
	|| *y != param->p_xy[1]))
		return (3);
	return (0);
}

void	key_press2(t_param *param, int x, int y, int *count)
{
	char	*count_itoa;

	*count += 1;
	count_itoa = ft_itoa(*count);
	write (1, count_itoa, ft_strlen(count_itoa));
	write (1, "\n", 1);
	free (count_itoa);
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
	if (param->elements->c == 0)
		change_exit (param);
	if (check >= 2)
		key_press2(param, x, y, &count);
	else if (check == 1)
	{
		key_press2(param, x, y, &count);
		if (param->elements->c == 0)
		{
			write (1, "EXIT SUCCESS!!\n", 15);
			free_param(param);
			exit(0);
		}
	}
	return (0);
}

int	program_exit(t_param *param)
{
	free_param(param);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_param		*param;

	if (argc != 2)
	{
		write (2, "Error\n", 6);
		write (2, strerror(errno), ft_strlen(strerror(errno)));
		exit (errno);
	}
	param = make_param();
	param->elements = make_elements(param);
	make_map(argv[argc - 1], param);
	param->mlx_ptr = mlx_init();
	if (param->mlx_ptr == NULL)
		error_message ("MLX init error\n", param);
	param->win_ptr = mlx_new_window(param->mlx_ptr, \
	param->elements->map_w * 64, param->elements->map_h * 64, argv[1]);
	if (param->win_ptr == NULL)
		error_message ("MLX_window error\n", param);
	open_image(param->mlx_ptr, param);
	print_map(param);
	mlx_hook(param->win_ptr, 2, 0, &key_press, param);
	mlx_hook(param->win_ptr, 17, 0, &program_exit, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
