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
	int	slime[2];
}		t_elements;

typedef struct s_image
{
	void	*map;
	void	*wall;
	void	*player;
	void	*exit;
	void	*goal;
	void	*exit_open;
	int		x;
	int		y;
}		t_image;

typedef struct s_enemy
{
	void	*slime1;
	void	*slime2;
	void	*slime3;
	void	*slime4;
	void	*slime5;
	void	*slime6;
	void	*slime7;
	int		x;
	int		y;
}		t_enemy;

typedef struct s_param
{
	struct s_elements	*elements;
	char				**map;
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_image		*img;
	struct s_enemy		*enemy;
	int					p_xy[2];
}		t_param;

void		make_map(char *argv, t_param *param);
char		**check_map(int fd, t_elements *elements);
void		error_stdin(void);
t_image		*open_image(void *mlx_ptr);
t_elements	*make_elements(void);
t_param		*make_param(void);
t_enemy		*make_enemy(void *mlx);
void		print_map(t_param *param);
void		print_map2(t_param *param);
#endif