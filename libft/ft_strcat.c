/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:57:02 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/27 13:38:44 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	i;

	d = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
