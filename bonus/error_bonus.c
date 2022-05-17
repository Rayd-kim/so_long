/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:37 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:56:06 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_img(t_param *param)
{
	if (param->img != NULL && param->mlx_ptr != NULL)
	{
		if (param->img->map != NULL)
			mlx_destroy_image (param->mlx_ptr, param->img->map);
		if (param->img->wall != NULL)
			mlx_destroy_image (param->mlx_ptr, param->img->wall);
		if (param->img->player != NULL)
			mlx_destroy_image (param->mlx_ptr, param->img->player);
		if (param->img->goal != NULL)
			mlx_destroy_image (param->mlx_ptr, param->img->goal);
		if (param->img->exit != NULL)
			mlx_destroy_image (param->mlx_ptr, param->img->exit);
	}
	free (param->img);
}

static void	free_elements(t_param *param)
{
	free(param->elements->slime_x);
	free(param->elements->slime_y);
	free (param->elements);
}

static void	free_enemy(t_param *param)
{
	if (param->enemy != NULL && param->mlx_ptr)
	{
		if (param->enemy->slime1 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime1);
		if (param->enemy->slime2 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime2);
		if (param->enemy->slime3 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime3);
		if (param->enemy->slime4 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime4);
		if (param->enemy->slime5 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime5);
		if (param->enemy->slime6 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime6);
		if (param->enemy->slime7 != NULL)
			mlx_destroy_image (param->mlx_ptr, param->enemy->slime7);
	}
	free (param->enemy);
}

void	free_param(t_param *param)
{
	int	i;

	i = -1;
	if (param->map != NULL)
	{
		while (param->map[++i] != NULL)
			free (param->map[i]);
		free (param->map[i]);
	}
	free (param->map);
	free_elements(param);
	free_img(param);
	free_enemy(param);
	if (param->mlx_ptr != NULL && param->win_ptr != NULL)
		mlx_destroy_window (param->mlx_ptr, param->win_ptr);
	free (param);
}
