/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:50 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:02:28 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	change_exit(t_param *param)
{
	mlx_destroy_image (param->mlx_ptr, param->img->exit);
	param->img->exit = mlx_xpm_file_to_image(param->mlx_ptr, \
	"./Texture/exit_open.xpm", &param->img->x, &param->img->y);
	if (param->img->exit == NULL)
		error_message ("Image open error\n", param);
}
