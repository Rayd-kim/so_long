#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <stdlib.h>
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

# define key_w		13
# define key_a		0
# define key_s		1
# define key_d		2
# define key_esc	53

typedef	struct	s_elements
{
	int	map_W;
	int	map_H;
	int	C;
	int	E;
	int	P;
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
	int				P_XY[2];
}		t_param;

char	**check_map(int fd, t_elements *elements);

#endif