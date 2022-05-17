/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:50 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:32:34 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_image(void *mlx_ptr, t_param *param)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (img == 0)
		error_stdin(param);
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
	param->img = img;
	if (img->map == NULL || img->wall == NULL || img->exit == NULL \
	|| img->goal == NULL || img->player == NULL)
		error_message ("Image open error\n", param);
}

t_elements	*make_elements(t_param *param)
{
	t_elements	*elements;

	elements = (t_elements *)malloc(sizeof(t_elements));
	if (elements == 0)
		error_stdin(param);
	ft_memset(elements, 0, sizeof(t_elements));
	return (elements);
}

t_param	*make_param(void)
{
	t_param	*ret;

	ret = (t_param *)malloc(sizeof(t_param));
	if (ret == 0)
	{
		write (2, "Error\n", 6);
		write (2, strerror(errno), ft_strlen(strerror(errno)));
		exit (errno);
	}
	ft_memset(ret, 0, sizeof(t_param));
	return (ret);
}

void	make_enemy(void *mlx, t_param *param)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (enemy == 0)
		error_stdin(param);
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
	param->enemy = enemy;
	if (enemy->slime1 == NULL || enemy->slime2 == NULL || enemy->slime3 == NULL \
	|| enemy->slime4 == NULL || enemy->slime5 == NULL || enemy->slime6 == NULL \
	|| enemy->slime7 == NULL)
		error_message ("Enemy image open error\n", param);
}

void	change_exit(t_param *param)
{
	mlx_destroy_image (param->mlx_ptr, param->img->exit);
	param->img->exit = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./Texture/exit_open.xpm", &param->img->x, &param->img->y);
	if (param->img->exit == NULL)
		error_message ("Image open error\n", param);
}
