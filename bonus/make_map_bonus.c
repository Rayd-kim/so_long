/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:45 by youskim           #+#    #+#             */
/*   Updated: 2022/05/17 19:23:35 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_map(int fd, int *map_len, t_param *param)
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
		if (map == NULL)
			error_message("strjoin error\n", param);
		free (temp);
		free (free_map);
		temp = get_next_line(fd);
	}
	free(temp);
	return (map);
}

void	check_wall(char	**map, t_elements *elements, t_param *param)
{
	int	i;
	int	k;

	if (elements->c < 1 || elements->e < 1 || elements->p != 1)
		error_message("Component error\n", param);
	i = 0;
	while (map[i] != NULL)
	{
		k = 0;
		if ((int)ft_strlen(map[i]) != elements->map_w)
			error_message("Not rectangular\n", param);
		while (map[i][k] != '\0')
		{
			if ((i == 0 && map[i][k] != '1' ) || \
			(i == (elements->map_h - 1) && map[i][k] != '1'))
				error_message("Not surrounded\n", param);
			else if ((k == 0 && map[i][k] != '1' ) || \
			(k == (elements->map_w - 1) && map[i][k] != '1'))
				error_message("Not surrounded\n", param);
			k++;
		}
		i++;
	}
}

void	check_map2(t_elements *elements, char *map, t_param *param)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			elements->map_h += 1;
		else if (map[i] == 'C')
			elements->c += 1;
		else if (map[i] == 'E')
			elements->e += 1;
		else if (map[i] == 'P')
			elements->p += 1;
		else if (map[i] == 'S')
			elements->s += 1;
		else if (map[i] != '0' && map[i] != '1')
			error_message("Component error\n", param);
		i++;
	}
}

char	**check_map(int fd, t_elements *elements, t_param *param)
{
	char		*map;
	char		**real_map;

	map = read_map(fd, &elements->map_w, param);
	if (map == NULL)
		error_message("Can't read map\n", param);
	elements->map_h = 1;
	check_map2(elements, map, param);
	if (elements->map_w > 40 || elements->map_h > 21)
		error_message("Map too big\n", param);
	real_map = ft_split(map, '\n');
	free(map);
	if (real_map == NULL)
		error_message("Map split fail\n", param);
	check_wall(real_map, elements, param);
	return (real_map);
}

void	make_map(char *argv, t_param *param)
{
	int		fd;
	int		i;
	int		argv_len;
	char	*ber;

	fd = open (argv, O_RDONLY);
	if (fd < 0)
		error_stdin(param);
	ber = ".ber";
	argv_len = ft_strlen(argv);
	i = 0;
	while (i < 5)
	{
		if (argv[argv_len - i] == ber[4 - i])
			i++;
		else
			error_message("Map is not .ber\n", param);
	}
	param->map = check_map(fd, param->elements, param);
	close(fd);
}
