/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:15:52 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/23 02:20:36 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_params(t_params *game, int x)
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

void	initialize_ray_step(t_params *game)
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

void	calculate_wall_distance(t_params *game)
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

unsigned long	translate_color(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	render_column(t_params *game, int x)
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
			+ x] = translate_color(game->c_color[0], game->c_color[1],
				game->c_color[2]);
	if (mid <= game->drawend)
		configure_wall_texture(game, mid, x);
	mid = game->drawend;
	while (++mid < 450)
		game->img_data[mid * game->size_line / 4
			+ x] = translate_color(game->f_color[0], game->f_color[1],
				game->f_color[2]);
}
