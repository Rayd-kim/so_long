#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
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
	int	s;
	int	*slime_x;
	int	*slime_y;
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
char		**check_map(int fd, t_elements *elements, t_param *param);
void		error_stdin(t_param *param);
void		error_message(char *str, t_param *param);
void		free_param(t_param *param);
void		first_error(void);
void		open_image(void *mlx_ptr, t_param *param);
void		make_enemy(void *mlx, t_param *param);
t_elements	*make_elements(t_param *param);
t_param		*make_param(void);
void		change_exit(t_param *param);

void		print_map(t_param *param);
void		print_map2(t_param *param);
void		slime_check(t_param *param, int i, int k);
int 		*slime_position(t_param *param);
void		draw_slime(t_param *param, void *map, void *slime);
int			nothing(t_param *param);
#endif