/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:29:34 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/26 21:37:17 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	apply_texture_to_column(t_params *game, int mid, int x, t_texture *t)
{
	game->step = 1.0 * game->texture_north->height / game->lineheight;
	game->tex_pos = (game->drawstart - 450 / 2
			+ game->lineheight / 2) * game->step;
	while (mid <= game->drawend)
	{
		game->tex_y = (int)game->tex_pos &(t->height - 1);
		game->tex_pos += game->step;
		if (mid < 450 && x < 600)
			game->img_data[mid * game->size_line / 4 + x]
				= t->data_img_text[game->tex_y
				* t->size_line / 4 + game->tex_x];
		mid += 1;
	}
}

void	calculate_wall_hitpoint(t_params *game)
{
	if (game->side == 1)
		game->wall = game->real_x + ((game->y - game->real_y
					+ (1 - game->stepy) / 2)
				/ game->raydiry) * game->raydirx;
	else
		game->wall = game->real_y + ((game->x - game->real_x
					+ (1 - game->stepx) / 2)
				/game->raydirx) * game->raydiry;
	game->wall -= floor(game->wall);
}

void	configure_wall_texture(t_params *game, int mid, int x)
{
	calculate_wall_hitpoint(game);
	if (game->side == 0 && game->raydirx >= 0)
	{
		game->tex_x = (int)(game->wall * game->texture_south->width);
		game->tex_x = game->texture_south->width - game->tex_x - 1;
		apply_texture_to_column(game, mid, x, game->texture_south);
	}
	else if (game->side == 0 && game->raydirx < 0)
	{
		game->tex_x = (int)(game->wall * game->texture_north->width);
		apply_texture_to_column(game, mid, x, game->texture_north);
	}
	else if (game->side == 1 && game->raydiry < 0)
	{
		game->tex_x = (int)(game->wall * game->texture_west->width);
		apply_texture_to_column(game, mid, x, game->texture_west);
	}
	else if (game->side == 1 && game->raydiry >= 0)
	{
		game->tex_x = (int)(game->wall * game->texture_east->width);
		apply_texture_to_column(game, mid, x, game->texture_east);
	}
}
