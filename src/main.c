/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:23:51 by kyacini           #+#    #+#             */
/*   Updated: 2023/11/02 12:22:04 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	char	**map;
	t_params game;

	map = error_treatment(argc, argv);
	if(map)
		check_params_map(map, &game);
	if (map == NULL)
		exit (1);
}