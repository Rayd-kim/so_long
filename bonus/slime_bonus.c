#include "so_long_bonus.h"

void	slime_check(t_param *param, int i, int k)
{
	static int	index = 0;

	param->elements->slime_x[index] = k;
	param->elements->slime_y[index] = i;
	index += 1;
}

int *slime_position(t_param *param)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * param->elements->s);
	if (ret == 0)
		error_stdin(param);
	ft_memset(ret, 0, param->elements->s * sizeof(int));
	return (ret);
}

void	draw_slime(t_param *param, void *map, void *slime)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
    int     i;

	mlx = param->mlx_ptr;
	win = param->win_ptr;
	i = 0;
	while (i < param->elements->s)
	{
		x = param->elements->slime_x[i];
		y = param->elements->slime_y[i];
		mlx_put_image_to_window(mlx, win, map, x * 64, y * 64);
		mlx_put_image_to_window(mlx, win, slime, x * 64, y * 64);
    	i++;
	}
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
