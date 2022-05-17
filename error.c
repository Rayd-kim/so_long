/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:37 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:03:39 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_stdin(t_param *param)
{
	write (2, "Error\n", 6);
	write (2, strerror(errno), ft_strlen(strerror(errno)));
	free_param(param);
	exit (errno);
}

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
	free (param->elements);
	free_img(param);
	free (param->img);
	if (param->mlx_ptr != NULL && param->win_ptr != NULL)
		mlx_destroy_window (param->mlx_ptr, param->win_ptr);
	free (param);
}

void	error_message(char *str, t_param *param)
{
	int	i;

	i = ft_strlen(str);
	write (2, "Error\n", 6);
	write (2, str, i);
	free_param (param);
	exit (1);
}
