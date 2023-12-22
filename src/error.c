/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 03:36:03 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/22 13:10:31 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
				return (write(1, "Error\nThe map need walls\n", 25), 0);
			else if(str[i][j] == '0' || str[i][j] == 'N'
				|| str[i][j] == 'S' || str[i][j] == 'E' || str[i][j] == 'W')
			{
				if (test_border_zero(str[i - 1][j]) || test_border_zero(str[i + 1][j]))
					return (write(1, "Error\nThe map need walls\n", 25), 0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int search_xy(t_params *game)
{
	int i;
	int j;
	int buff;

	i = 0;
	j = 0;
	buff = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if((game->map[i][j] == 'S' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E') && buff == 0)
			{
				game->x = i;
				game->y = j;
				buff = 1;
			}
			else if((game->map[i][j] == 'S' || game->map[i][j] == 'N'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E') && buff == 1)
				return 0;
			j++;
		}
		j = 0;
		i++;
	}
	return 1;
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
				return (write(1, "Error\nWrong block\n", 18), 0);
			j++;
		}
		j = 0;
		i++;
	}
	if (c == 0 || c > 1)
		return (write(1, "Error\nOne character allowed\n", 28), 0);
	return (1);
}

int	check_nl(char *str)
{
	char	buff[2];
	char	mem;
	int		fd;
	int		num;

	fd = open(str, O_RDONLY);
	num = 0;
	buff[1] = '\0';
	read(fd, buff, 1);
	while (read(fd, buff, 1))
	{
		if (buff[0] == '\n' && mem == '\n' && num >= 7)
			return (write(1, "Error\nProbleme with a new line\n", 31), 0);
		if(mem != '\n' && buff[0] == '\n')
			num++;
		mem = buff[0];
	}
	if (buff[0] == '\n')
		return (0);
	close(fd);
	return (1);
}