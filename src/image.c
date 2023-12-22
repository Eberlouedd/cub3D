/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:29:34 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/22 14:18:16 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	tex_loop(t_params *game, int mid, int x, t_texture *t)
{
	game->step = 1.0 * game->texture_north->height / game->lineheight;
	game->texPos = (game->drawstart - 450 / 2 + game->lineheight / 2) * game->step;
	while (mid <= game->drawend)
	{
		game->texY = (int)game->texPos &(t->height - 1);
		game->texPos += game->step;
		if (mid < 450 && x < 600)
			game->img_data[mid * game->size_line / 4 + x] = t->data_img_text[game->texY
				* t->size_line / 4 + game->texX];
		mid += 1;
	}
}

//wallx : coordonnée sur x de la colonne que l'on veut utiliser
//tex : coordonnée sur x dans la texture
void	init_imagep1(t_params *game)
{
	if (game->side == 1)
		game->wall = game->real_y + ((game->y - game->real_y + (1 - game->stepy) / 2)
				/ game->raydiry) * game->raydirx;
	else
		game->wall = game->real_x + ((game->x - game->real_x + (1 - game->stepx) / 2)
				/game->raydirx) * game->raydiry;
	game->wall -= floor(game->wall);
}

void	init_image(t_params *game, int mid, int x)
{
	init_imagep1(game);
	if (game->side == 0 && game->raydirx >= 0)
	{
		game->texX = (int)(game->wall * game->texture_south->width);
		game->texX = game->texture_south->width - game->texX - 1;
		tex_loop(game, mid, x, game->texture_south);
	}
	else if (game->side == 0 && game->raydirx < 0)
	{
		game->texX = (int)(game->wall * game->texture_north->width);
		game->texX = game->texture_north->width - game->texX - 1;
		tex_loop(game, mid, x, game->texture_north);
	}
	else if (game->side == 1 && game->raydiry < 0)
	{
		game->texX = (int)(game->wall * game->texture_west->width);
		tex_loop(game, mid, x, game->texture_west);
	}
	else if (game->side == 1 && game->raydiry >= 0)
	{
		game->texX = (int)(game->wall * game->texture_east->width);
		tex_loop(game, mid, x, game->texture_east);
	}
}
