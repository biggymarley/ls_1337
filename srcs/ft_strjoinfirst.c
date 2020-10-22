/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:38:30 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 03:18:03 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	ft_strjoinfirst(char const *s1, char s2, char **str)
{
	int		i;
	int		j;
	int		c;
	char	*chi;

	i = 0;
	j = 0;
	chi = *str;
	c = ft_strlen(s1);
	if (chi)
	{
		chi[i++] = s2;
		while (s1[j])
			chi[i++] = s1[j++];
		chi[i] = '\0';
	}
	return ;
}
