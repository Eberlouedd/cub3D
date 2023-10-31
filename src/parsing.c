/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/10/30 15:46:16 by kyacini          ###   ########.fr       */
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
		if(!have_walls(map_test))
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

	i = 0;
	if (!only_one(str[0]))
	{
		write(1, "Error\nThe map need walls\n", 25);
		return (0);
	}
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
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
	return ((str[0] != 'N' && str[1] != 'O')
		&& (str[0] != 'S' && str[1] != 'U')
		&& (str[0] != 'W' && str[1] != 'E')
		&& (str[0] != 'E' && str[1] != 'A')
		&& str[0] != 'F' && str[0] != 'C');
}

void get_params_map(char **map, t_params *game)
{
	int i;
	char *stock;

	stock = "NSWEFC";
	i = 0;
	while (map[i])
	{
		if(!begin_line(map[i]) && !only_one(stock))
		{
			free_double_char(map);
			write(1, "Error\nElements mistake\n", 24);
			exit(1);
		}
		else if()
	}
}

