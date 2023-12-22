/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:15:52 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/22 14:21:14 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	raycasting_init(t_params *game, int x)
{
	game->camerax = 2 * x / (double)600 - 1;
	game->raydirx = game->dirx + game->planx * game->camerax;
	game->raydiry = game->diry + game->plany * game->camerax;
	game->x = (int)game->real_x;
	game->y = (int)game->real_y;
	if (game->raydirx == 0)
		game->deltadistx = 1e30;
	else
		game->deltadistx = sqrt (1 + (game->raydiry * game->raydiry)
				/ (game->raydirx * game->raydirx));
	if (game->raydiry == 0)
		game->deltadisty = 1e30;
	else
		game->deltadisty = sqrt(1 + (game->raydirx * game->raydirx)
				/ (game->raydiry * game->raydiry));
}

void	get_firstdist(t_params *game)
{
	if (game->raydirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (game->real_x - game->x)
			* game->deltadistx;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->x + 1.0 - game->real_x)
			* game->deltadistx;
	}
	if (game->raydiry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (game->real_y - game->y)
			* game->deltadisty;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->y + 1.0 - game->real_y)
			* game->deltadisty;
	}
}

void	get_dist(t_params *game)
{
	game->hit = 0;
	game->perpwalldist = 0;
	while (game->hit == 0)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->x += game->stepx;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->y += game->stepy;
			game->side = 1;
		}
		if (game->map[game->x][game->y] == '1')
			game->hit = 1;
	}
	if (game->side == 0)
		game->perpwalldist = (((double)game->x - game->real_x
					+ (1 - (double)game->stepx) / 2) / game->raydirx);
	else
		game->perpwalldist = (((double)game->y - game->real_y
					+ (1 - (double)game->stepy) / 2) / game->raydiry);
}

unsigned long	creatergb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void draw_game(t_params *game, int x)
{
	int	mid;

	mid = -1;
	game->lineheight = (int)(450 / game->perpwalldist);
	game->drawstart = -game->lineheight / 2 + 450 / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheight / 2 + 450 / 2;
	if (game->drawend >= 450 || game->drawend < 0)
		game->drawend = 450 - 1;
	game->drawend = 450 - game->drawstart;
	while (++mid < game->drawstart)
		game->img_data[mid * game->size_line / 4
			+ x] = creatergb(game->c_color[0], game->c_color[1], game->c_color[2]);
	if (mid <= game->drawend)
		init_image(game, mid, x);
	mid = game->drawend;
	while (++mid < 450)
		game->img_data[mid * game->size_line / 4
			+ x] = creatergb(game->f_color[0], game->f_color[1], game->f_color[2]);
}

void	raycasting_loop(t_params *game)
{
	int	x;

	x = 0;

	while (x < 600)
	{
		raycasting_init(game, x);
		get_firstdist(game);
		get_dist(game);
		draw_game(game, x);
		x++;
	}
}