/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:02:24 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/23 02:24:17 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	forward(t_params *game)
{
	if (is_passable_space(game->real_x + (game->dirx * game->speed),
			game->real_y, game))
		game->real_x += game->dirx * game->speed;
	if (is_passable_space(game->real_x,
			game->real_y + (game->diry * game->speed), game))
		game->real_y += game->diry * game->speed;
}

void	back(t_params *game)
{
	if (is_passable_space(game->real_x - game->dirx * (game->speed),
			game->real_y, game))
		game->real_x -= game->dirx * game->speed;
	if (is_passable_space(game->real_x,
			game->real_y - game->diry * (game->speed), game))
		game->real_y -= game->diry * game->speed;
}

void	left(t_params *game)
{
	if (is_passable_space(game->real_x - game->diry * (game->speed),
			game->real_y, game))
		game->real_x -= game->diry * game->speed;
	if (is_passable_space(game->real_x,
			game->real_y + game->dirx * (game->speed), game))
		game->real_y += game->dirx * game->speed;
}

void	right(t_params *game)
{
	if (is_passable_space(game->real_x + game->diry * (game->speed),
			game->real_y, game))
		game->real_x += game->diry * game->speed;
	if (is_passable_space(game->real_x,
			game->real_y - game->dirx * (game->speed), game))
		game->real_y -= game->dirx * game->speed;
}

void	rotate(t_params *game, int way)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = game->planx;
	olddirx = game->dirx;
	game->dirx = game->dirx * cos(way * game->rotation / 2)
		- game->diry * sin(way * game->rotation / 2);
	game->diry = olddirx * sin(way * game->rotation / 2)
		+ game->diry * cos(way * game->rotation / 2);
	game->planx = game->planx * cos(way * game->rotation / 2)
		- game->plany * sin(way * game->rotation / 2);
	game->plany = oldplanx * sin(way * game->rotation / 2)
		+ game->plany * cos(way * game->rotation / 2);
}
