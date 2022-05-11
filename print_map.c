/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:53 by youskim           #+#    #+#             */
/*   Updated: 2022/05/10 20:08:40 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_bg(t_param *param)
{
	int	i;
	int	k;

	i = 0;
	while (i < param->elements->map_w)
	{
		k = 0;
		while (k < param->elements->map_h)
		{
			mlx_put_image_to_window(param->mlx_ptr, \
			param->win_ptr, param->img->map, i * 64, k * 64);
			k++;
		}
		i++;
	}
}

static void	print_img(t_param *param, void *img, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = param->mlx_ptr;
	win = param->win_ptr;
	mlx_put_image_to_window(mlx, win, img, x * 64, y * 64);
}

void	print_map(t_param *param)
{
	int		i;
	int		k;

	print_bg(param);
	i = -1;
	while (param->map[++i])
	{
		k = -1;
		while (param->map[i][++k])
		{
			if (param->map[i][k] == '1')
				print_img(param, param->img->wall, k, i);
			else if (param->map[i][k] == 'E')
				print_img(param, param->img->exit, k, i);
			else if (param->map[i][k] == 'C')
				print_img(param, param->img->goal, k, i);
			else if (param->map[i][k] == 'P')
			{
				param->p_xy[0] = k;
				param->p_xy[1] = i;
				print_img(param, param->img->player, \
				param->p_xy[0], param->p_xy[1]);
			}
		}
	}
}

void	print_map2(t_param *param)
{
	int		i;
	int		k;

	print_bg(param);
	i = 0;
	while (param->map[i])
	{
		k = 0;
		while (param->map[i][k])
		{
			if (param->map[i][k] == '1')
				print_img(param, param->img->wall, k, i);
			else if (param->map[i][k] == 'E')
				print_img(param, param->img->exit, k, i);
			else if (param->map[i][k] == 'C')
				print_img(param, param->img->goal, k, i);
			//else if (param->map[i][k] == 'P')
			//	print_img(param, param->img->player, param->p_xy[0], param->p_xy[1]);
			k++;
		}
		i++;
	}
	print_img(param, param->img->player, \
	param->p_xy[0], param->p_xy[1]);
}
