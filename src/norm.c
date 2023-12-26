/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 04:32:25 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/23 03:28:31 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	count_stock_inc(int *c, char *s)
{
	*c += 1;
	*s = '1';
}

void	stock_var_init(char s[6], int *i, int *c, int *j)
{
	s[0] = 'N';
	s[1] = 'S';
	s[2] = 'W';
	s[3] = 'E';
	s[4] = 'F';
	s[5] = 'C';
	*i = 0;
	*c = 0;
	*j = 0;
}

void	count_var_i_inc(int c, int *v, int *i)
{
	if (c > 6)
		*v = 1;
	*i += 1;
}

void	affect_position(t_params *game, int i, int j, int *buff)
{
	game->x = i;
	game->y = j;
	*buff = 1;
}

int	create_map(t_params *game, char **fc, char **cc, char **map)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->buff + 1));
	game->map[game->buff] = NULL;
	while (fc[i] && cc[i] && i < 3)
	{
		game->f_color[i] = ft_atoi(fc[i]);
		game->c_color[i] = ft_atoi(cc[i]);
		if (game->f_color[i] < 0 || game->f_color[i] > 255
			|| game->c_color[i] < 0 || game->c_color[i] > 255)
			return (free_double_char(map), free_double_char(cc),
				free_double_char(fc), free_parsing_failure(game),
				write(1, "Error\nProbleme with colors\n", 27), 0);
		i++;
	}
	if (i != 3)
		return (write(1, "Error\nProbleme with colors\n", 27), 0);
	i = 0;
	while (i < game->buff)
	{
		game->map[i] = ft_strdup(map[i + 6]);
		i++;
	}
	return (free_buffers(fc, cc, map), search_xy(game));
}
