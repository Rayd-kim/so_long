/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:24:56 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:02:32 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_elements
{
	int	map_w;
	int	map_h;
	int	c;
	int	e;
	int	p;
}		t_elements;

typedef struct s_image
{
	void	*map;
	void	*wall;
	void	*player;
	void	*exit;
	void	*goal;
	int		x;
	int		y;
}		t_image;

typedef struct s_param
{
	struct s_elements	*elements;
	char				**map;
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_image		*img;
	int					p_xy[2];
}		t_param;

void		make_map(char *argv, t_param *param);
void		open_image(void *mlx_ptr, t_param *param);
t_elements	*make_elements(t_param *param);
t_param		*make_param(void);
void		print_map(t_param *param);
void		print_map2(t_param *param);
void		change_exit(t_param *param);
void		error_stdin(t_param *param);
void		error_message(char *str, t_param *param);
void		free_param(t_param *param);
#endif
