/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:21:37 by youskim           #+#    #+#             */
/*   Updated: 2022/05/10 18:46:05 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_stdin(void)
{
	write (2, "Error\n", 6);
	write (2, strerror(errno), ft_strlen(strerror(errno)));
	exit (errno);
}

void	error_null(void)
{
	write (2, "Error\n", 6);
	write (2, "Can't read map\n", 15);
	exit (1);
}

void	error_component(void)
{
	write (2, "Error\n", 6);
	write (2, "Component not enough\n", 21);
	exit (1);
}

void	error_rectangular(void)
{
	write (2, "Error\n", 6);
	write (2, "Not rectangular\n", 16);
	exit (1);
}

void	error_wall(void)
{
	write (2, "Error\n", 6);
	write (2, "Not surrounded\n", 15);
	exit (1);
}
