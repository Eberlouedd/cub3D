/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:29:05 by kyacini           #+#    #+#             */
/*   Updated: 2023/12/08 00:02:59 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_game_data(t_data *data)
{
    data->planx = 0;
    data->plany = 0.66;
}

void make_window(t_params *game, t_data *data)
{
    int i;
    int j;
    void *img;
    void *img_wall;
    char *img_data;
    char *img_data_wall;
    int bpp;
    int bpp_wall;
    int size_line;
    int size_line_wall;
    int endian;
    int endian_wall;
    int color = 0xFF0000;
    int color_wall = 0xFFFFFF;
    
    i = 0;
    while(game->map[i])
    {
        i++;
    }
	data->mlx_win = mlx_new_window(data->mlx, ft_strlen(game->map[0]) * 20, i * 20, "Cub3D");
    img = mlx_new_image(data->mlx, 10, 10);
    img_wall = mlx_new_image(data->mlx, 20, 20);
    img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    img_data_wall = mlx_get_data_addr(img_wall, &bpp_wall, &size_line_wall, &endian_wall);
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            int index = x * (bpp / 8) + y * size_line;
            *(int*)(img_data + index) = color;
        }
    }
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            int index = x * (bpp_wall / 8) + y * size_line_wall;
            *(int*)(img_data_wall + index) = color_wall;
        }
    }
    i = 0;
    j = 0;
    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if(game->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, img_wall, j*20, i*20);
            else if (game->map[i][j] == 'N')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, img, j*20 + 10, i*20 + 10);
            }
            j++;
        }
        j = 0;
        i++;
    }
}