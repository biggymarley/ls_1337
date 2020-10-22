/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_flagr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 04:41:25 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 03:43:06 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	rec_r(char **tab, unsigned short op)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putendl(":");
		read_file(tab[i], op);
		if (tab[i] != '\0' && tab[i + 1] != '\0')
			ft_putchar('\n');
		free(tab[i++]);
	}
}

void	rec_rr(char **tab, unsigned short op)
{
	int c;

	c = rev_tab(tab) - 1;
	while (c >= 0)
	{
		ft_putstr(tab[c]);
		ft_putstr(":\n");
		read_file(tab[c], op);
		if (c > 0)
			ft_putchar('\n');
		free(tab[c--]);
	}
}
