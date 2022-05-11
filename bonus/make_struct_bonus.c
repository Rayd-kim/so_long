/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:50 by youskim           #+#    #+#             */
/*   Updated: 2022/05/10 15:31:47 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_image	*open_image(void *mlx_ptr)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (img == 0)
		error_stdin();
	ft_memset(img, 0, sizeof(t_image));
	img->map = mlx_xpm_file_to_image(mlx_ptr, \
	"./Texture/map.xpm", &img->x, &img->y);
	img->wall = mlx_xpm_file_to_image(mlx_ptr, \
	"./Texture/wall.xpm", &img->x, &img->y);
	img->exit = mlx_xpm_file_to_image(mlx_ptr, \
	"./Texture/exit_close.xpm", &img->x, &img->y);
	img->goal = mlx_xpm_file_to_image(mlx_ptr, \
	"./Texture/Chicken.xpm", &img->x, &img->y);
	img->player = mlx_xpm_file_to_image(mlx_ptr, \
	"./Texture/Player.xpm", &img->x, &img->y);
	img->exit_open = mlx_xpm_file_to_image(mlx_ptr, \
	"./Texture/exit_open.xpm", &img->x, &img->y);
	return (img);
}

t_elements	*make_elements(void)
{
	t_elements	*elements;

	elements = (t_elements *)malloc(sizeof(t_elements));
	if (elements == 0)
		error_stdin();
	ft_memset(elements, 0, sizeof(t_elements));
	return (elements);
}

t_param	*make_param(void)
{
	t_param	*ret;

	ret = (t_param *)malloc(sizeof(t_param));
	if (ret == 0)
		error_stdin();
	ft_memset(ret, 0, sizeof(t_param));
	return (ret);
}

t_enemy	*make_enemy(void *mlx)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (enemy == 0)
		error_stdin();
	ft_memset(enemy, 0, sizeof(t_enemy));
	enemy->slime1 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime1.xpm", &enemy->x, &enemy->y);
	enemy->slime2 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime2.xpm", &enemy->x, &enemy->y);
	enemy->slime3 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime3.xpm", &enemy->x, &enemy->y);
	enemy->slime4 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime4.xpm", &enemy->x, &enemy->y);
	enemy->slime5 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime5.xpm", &enemy->x, &enemy->y);
	enemy->slime6 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime6.xpm", &enemy->x, &enemy->y);
	enemy->slime7 = mlx_xpm_file_to_image(mlx, \
	"./Texture/slime7.xpm", &enemy->x, &enemy->y);
	return (enemy);
}
