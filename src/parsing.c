/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/11/20 00:30:50 by kyacini          ###   ########.fr       */
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

int error_treatment(int nb_params, char **params, t_params *game)
{
	char	**map_test;

	if (nb_params != 2)
	{
		write(1, "Error\nWrong parameters\n", 23);
		return 0;
	}
	check_extension(params[1]);
	map_test = get_map(params[1]);
	if (map_test != NULL)
	{
		if(!check_params_map(map_test) || !have_walls(map_test) || !check_elements(map_test))
		{
			free(game);
			free_double_char(map_test);
			return 0;
		}
	}
	else
	{
		write(1, "Error\nCan't read file\n", 22);
		return 0;
	}
	return(get_params_map(map_test, game));
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

int check_elements(char **str)
{
	int i;
	int j;
	int c;

	i = 6;
	j = 6;
	c = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if(str[i][j] == 'N' || str[i][j] == 'S'
			|| str[i][j] == 'W' || str[i][j] == 'E')
				c++;
			else if(str[i][j] != '0' && str[i][j] != '1'
				&& str[i][j] != ' ')
			{
				write(1, "Error\nWrong block\n", 18);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (c == 0 || c > 1)
	{
		write(1, "Error\nOne character allowed\n", 28);
		return (0);
	}
	return (1);
}

int	have_walls(char **str)
{
	int	i;
	int j;

	i = 6;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if ((str[i][j] == '0' && j == 0) || (str[i][j] == '0' && i == 6))
			{
				printf("%c %d %d", str[i][j], i, j);
				write(1, "Error\nThe map need walls\n", 25);
				return (0);
			}
			else if(str[i][j] == '0' || str[i][j] == 'N'
				|| str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W')
			{
				if (test_border_zero(str[i - 1][j]) || test_border_zero(str[i + 1][j]))
				{
					write(1, "Error\nThe map need walls\n", 25);
					return (0);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int begin_line(char *str)
{
	return ((str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		|| (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
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
		else if(map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ')
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

int get_params_map(char **map, t_params *game)
{
	int i;
	int buff;
	char **fc;
	char **cc;

	i = 0;
	while (map[i])
	{
		if(map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
			game->north = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ')
			game->south = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
			game->west = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
			game->east = ft_substr(map[i], 3, ft_strlen(map[i]));
		else if(map[i][0] == 'C' && map[i][1] == ' ')
			cc = ft_split_free(ft_substr(map[i], 2, ft_strlen(map[i])), ',');
		else if(map[i][0] == 'F' && map[i][1] == ' ')
			fc = ft_split_free(ft_substr(map[i], 2, ft_strlen(map[i])), ',');
		i++;
	}
	buff = i - 6;
	i = 0;
	game->map = malloc(sizeof(char *) * (buff + 1));
	game->map[buff] = NULL;
	while (fc[i] && cc[i] && i < 3)
	{
		game->f_color[i] = ft_atoi(fc[i]);
		game->c_color[i] = ft_atoi(cc[i]);
		if(game->f_color[i] < 0 || game->f_color[i] > 255
			|| game->c_color[i] < 0 || game->c_color[i] > 255)
		return (free_double_char(map), free_double_char(cc), free_double_char(fc), free_parsing_failure(game),
			write(1, "Error\nProbleme with colors\n", 27), 0);
		i++;
	}
	if(i != 3)
	{
		write(1, "Error\nProbleme with colors\n", 27);
		return 0;
	}
	i = 0;
	while (i < buff)
	{
		game->map[i] = ft_strdup(map[i + 6]);
		i++;
	}
	free_double_char(cc);
	free_double_char(fc);
	free_double_char(map);
	return (1);
}
