#include "so_long.h"

char	*read_map(int fd, int *map_len)
{
	char	*temp;
	char	*map;
	char	*free_map;

	map = NULL;
	temp = get_next_line(fd);
	*map_len = ft_strlen(temp) - 1;
	while (temp != NULL)
	{
		free_map = map;
		map = ft_strjoin(map, temp);
		free (temp);
		free (free_map);
		temp = get_next_line(fd);
	}
	free(temp);
	return (map);
}

void	check_wall(char	**map, t_elements *elements)
{
	int	i;
	int	k;

	if (elements->C < 1 || elements->E < 1 || elements->P != 1)
		exit (1);
	i = 0;
	while (map[i] != NULL)
	{
		k = 0;
		if ((int)ft_strlen(map[i]) != elements->map_W)
			exit(1);
		while (map[i][k] != '\0')
		{
			if ((i == 0 && map[i][k] != '1' ) || \
			(i == elements->map_H && map[i][k] != '1'))
				exit (1);
			else if ((k == 0 && map[i][k] != '1' ) || \
			(k == elements->map_W && map[i][k] != '1'))
				exit (1);
			k++;
		}
		i++;
	}
}

char	**check_map(int fd, t_elements *elements)
{
	char		*map;
	char		**real_map;
	int			i;

	map = read_map(fd, &elements->map_W);
	elements->map_H = 1;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			elements->map_H += 1;
		else if (map[i] == 'C')
			elements->C += 1;
		else if (map[i] == 'E')
			elements->E += 1;
		else if (map[i] == 'P')
			elements->P += 1;
		i++;
	}
	real_map = ft_split(map, '\n');
	check_wall(real_map, elements);
	return (real_map);
}
