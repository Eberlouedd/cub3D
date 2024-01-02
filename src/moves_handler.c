/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:48:41 by kyacini           #+#    #+#             */
/*   Updated: 2024/01/02 14:26:46 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_passable_space(int x, int y, t_params *game)
{
	if (game->map[x][y] != '1')
		return (1);
	return (0);
}

int	key_event(int key, t_params *game)
{
	if (key == FORWARD)
		forward(game);
	if (key == BACK)
		back(game);
	if (key == LEFT)
		left(game);
	if (key == RIGHT)
		right(game);
	if (key == ROTATE_RIGHT)
		rotate(game, -1);
	if (key == ROTATE_LEFT)
		rotate(game, 1);
	if (key == ESC)
		exit_game("", game);
	return (0);
}

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	test_if_player(char c)
{
	return (c != '0'
		&& c != 'N' && c != 'E'
		&& c != 'W' && c != 'S');
}

int	check_walls(char **str, int i, int j)
{
	if ((!test_if_player(str[i][j])
		&& (j == 0 || j == ft_strlen(str[i]) - 1))
		|| (!test_if_player(str[i][j]) && (i == 6
		|| i == ft_strlen_double(str) - 1))
		|| (!test_if_player(str[i][j]) && (i > 6
		&& i < (ft_strlen_double(str) - 1)
		&& j > 0 && j < (ft_strlen(str[i]) - 1)
		&& (test_border_zero(str[i + 1][j])
		|| test_border_zero(str[i][j + 1]) || test_border_zero(str[i - 1][j])
		|| test_border_zero(str[i][j - 1])))))
		return (0);
	return (1);
}
