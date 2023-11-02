/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/11/02 16:21:51 by kyacini          ###   ########.fr       */
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
		free(stock);
		return (result);
	}
	return (NULL);
}

char **error_treatment(int nb_params, char **params)
{
	char	**map_test;

	if (nb_params != 2)
	{
		write(1, "Error\nWrong parameters\n", 23);
		return (NULL);
	}
	check_extension(params[1]);
	map_test = get_map(params[1]);
	if (map_test != NULL)
	{
		if(!check_params_map(map_test) || !have_walls(map_test))
		{
			free_double_char(map_test);
			return (NULL);
		}
	}
	else
	{
		write(1, "Error\nCan't read file\n", 22);
		return (NULL);
	}
	free_double_char(map_test);
	return (get_map(params[1]));
}

void	check_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size > 4)
	{
		if (str[size - 1] == 'b' && str[size - 2] == 'u'
			&& str[size - 3] == 'c' && str[size - 4] == '.')
			return ;
	}
	write(1, "Error\n", 6);
	write(1, "Wrong extension\n", 16);
	exit(1);
}

int	have_walls(char **str)
{
	int	i;

	i = 6;
	if (!only_one(str[i]))
	{
		write(1, "Error\nThe map need walls\n", 25);
		return (0);
	}
	while (str[i])
	{
		if (str[i][firstchar_position(str[i])] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
		{
			write(1, "Error\nThe map need walls\n", 25);
			return (0);
		}
		i++;
	}
	if (!only_one(str[i - 1]))
	{
		write(1, "Error\nThe map need walls\n", 25);
		return (0);
	}
	return (1);
}

int begin_line(char *str)
{
	return ((str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		|| (str[0] == 'S' && str[1] == 'U' && str[2] == ' ')
		|| (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		|| (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		|| (str[0] == 'F' && str[1] == ' ')
		|| (str[0] == 'C' && str[1] == ' '));
}

int check_params_map(char **map)
{
	int i;
	char stock[6];
	int count;
	int var;

	stock[0] = 'N';
	stock[1] = 'S';
	stock[2] = 'W';
	stock[3] = 'E';
	stock[4] = 'F';
	stock[5] = 'C';
	i = 0;
	count = 0;
	var = 0;

	while (map[i])
	{
		if((!begin_line(map[i]) && !only_one(stock)) || var)
			return (write(1, "Error\nElements mistake\n", 23), 0);
		else if(map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
		{
			count++;
			stock[0] = '1';
		}
		else if(map[i][0] == 'S' && map[i][1] == 'U' && map[i][2] == ' ')
		{
			count++;
			stock[1] = '1';
		}
		else if(map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
		{
			count++;
			stock[2] = '1';
		}
		else if(map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
		{
			count++;
			stock[3] = '1';
		}
		else if(map[i][0] == 'C' && map[i][1] == ' ')
		{
			count++;
			stock[5] = '1';
		}
		else if(map[i][0] == 'F' && map[i][1] == ' ')
		{
			count++;
			stock[4] = '1';
		}
		if(count > 6)
			var = 1;
		i++;
	}
	return (1);
}

void get_params_map(char **map, t_params *game)
{
	int i;
	int buff;

	i = 0;
	while (map[i])
	{
		if(map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
			game->north = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'S' && map[i][1] == 'U' && map[i][2] == ' ')
			game->south = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
			game->west = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
			game->east = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'C' && map[i][1] == ' ')
			game->c_color = ft_substr(map[i], 2, ft_strlen(map[i]));
		else if(map[i][0] == 'F' && map[i][1] == ' ')
			game->f_color = ft_substr(map[i], 2, ft_strlen(map[i]));
		i++;
	}
	buff = i - 6;
	i = 0;
	game->map = malloc(sizeof(char *) * (i + 1));
	game->map[i] = NULL;
	while (i < buff)
	{
		game->map[i] = map[i + 6];
		i++;
	}
}
