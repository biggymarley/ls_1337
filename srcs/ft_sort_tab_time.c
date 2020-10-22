/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 03:53:42 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:20:19 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	swab_tab(char **c, char **b)
{
	char *p;

	p = *b;
	*b = *c;
	*c = p;
}

void	norm(int *i, int j, struct stat *st, char **b)
{
	*i = j + 1;
	lstat(*b, &*st);
}

int		check_and_swap_time(char **tab, t_read *var)
{
	lstat(tab[var->i], &var->st1);
	if (var->st.st_mtime - var->st1.st_mtime < 0)
	{
		swab_tab(&tab[var->j], &tab[var->i]);
		norm(&var->i, var->j, &var->st, &tab[var->j]);
		return (1);
	}
	else if ((var->st.st_mtime == var->st1.st_mtime
			&& ft_strcmp(tab[var->j], tab[var->i]) > 0))
	{
		swab_tab(&tab[var->j], &tab[var->i]);
		norm(&var->i, var->j, &var->st, &tab[var->j]);
		return (1);
	}
	return (0);
}

void	ft_sort_tab_time(char **tab)
{
	t_read var;

	var.j = 0;
	var.i = 0;
	while (tab[var.j])
	{
		norm(&var.i, var.j, &var.st, &tab[var.j]);
		while (tab[var.i])
		{
			if (check_and_swap_time(tab, &var))
				continue;
			var.i++;
		}
		var.j++;
	}
}

void	ft_sort_tab(char **tab)
{
	int			i;
	int			j;

	j = 0;
	if (!*tab)
		return ;
	while (tab[j])
	{
		i = j + 1;
		while (tab[i])
		{
			if ((ft_strcmp(tab[j], tab[i])) > 0)
			{
				swab_tab(&tab[j], &tab[i]);
				i = j + 1;
				continue ;
			}
			i++;
		}
		j++;
	}
}
