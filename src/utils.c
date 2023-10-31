/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:41:58 by kyacini           #+#    #+#             */
/*   Updated: 2023/10/30 14:30:25 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	only_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	free_double_char(char **str)
{
	int	i;
	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}