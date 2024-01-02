/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:51 by kyacini           #+#    #+#             */
/*   Updated: 2024/01/02 14:28:18 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**get_map(char *str)
{
	char	*buff;
	char	*stock;
	char	**result;
	int		fd;

	stock = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nCan't read file\n", 22), NULL);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		stock = ft_strjoin(stock, buff);
		free(buff);
		buff = NULL;
	}
	close(fd);
	if (stock)
	{
		result = ft_split(stock, '\n');
		return (free(stock), result);
	}
	return (NULL);
}

void	check_extension(char *str, t_params *game)
{
	int	size;

	size = ft_strlen(str);
	if (size > 4)
	{
		if (str[size - 1] == 'b' && str[size - 2] == 'u'
			&& str[size - 3] == 'c' && str[size - 4] == '.')
			return ;
	}
	write(2, "Error\n", 6);
	write(2, "Wrong extension\n", 16);
	free(game);
	exit(1);
}

int	begin_line(char *str)
{
	return ((str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		|| (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		|| (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		|| (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		|| (str[0] == 'F' && str[1] == ' ')
		|| (str[0] == 'C' && str[1] == ' '));
}

int	check_params_map(char **map)
{
	int		i;
	char	stock[6];
	int		count;
	int		var;

	stock_var_init(stock, &i, &var, &count);
	while (map[i])
	{
		if ((!begin_line(map[i]) && !only_one(stock)) || var)
			return (write(2, "Error\nElements mistake\n", 23), 0);
		else if (map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
			count_stock_inc(&count, &stock[0]);
		else if (map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ')
			count_stock_inc(&count, &stock[1]);
		else if (map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
			count_stock_inc(&count, &stock[2]);
		else if (map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
			count_stock_inc(&count, &stock[3]);
		else if (map[i][0] == 'C' && map[i][1] == ' ')
			count_stock_inc(&count, &stock[5]);
		else if (map[i][0] == 'F' && map[i][1] == ' ')
			count_stock_inc(&count, &stock[4]);
		count_var_i_inc(count, &var, &i);
	}
	return (1);
}

int	get_params_map(char **map, t_params *game)
{
	int		i;
	char	**fc;
	char	**cc;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
			game->north = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if (map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ')
			game->south = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if (map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
			game->west = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if (map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
			game->east = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if (map[i][0] == 'C' && map[i][1] == ' ')
			cc = ft_split_free(ft_substr(map[i], 2, ft_strlen(map[i])), ',');
		else if (map[i][0] == 'F' && map[i][1] == ' ')
			fc = ft_split_free(ft_substr(map[i], 2, ft_strlen(map[i])), ',');
		i++;
	}
	game->buff = i - 6;
	return (create_map(game, fc, cc, map));
}
