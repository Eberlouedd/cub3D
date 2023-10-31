/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:53:03 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/21 13:43:07 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_chain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	new_chain = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	new_chain[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (j < ft_strlen(s2) || (s2[0] == '\0' && j <= ft_strlen(s2)))
	{
		while (i < ft_strlen(s1))
		{
			new_chain[i] = s1[i];
			i++;
		}
		new_chain[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	free(s2);
	return (new_chain);
}
