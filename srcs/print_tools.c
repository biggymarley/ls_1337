/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 02:10:12 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:21:05 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

t_max	*checker(t_list **ftab)
{
	t_list			*list;
	t_max			*max;
	int				*i;

	i = ft_memalloc(sizeof(int) * 6);
	ft_memset(i, 0, 6);
	list = *ftab;
	max = ft_memalloc(sizeof(t_max));
	while (list && list->content != NULL)
	{
		ft_max_finder(list, i);
		list = list->next;
	}
	max->gr = i[2];
	max->li = i[0];
	max->us = i[1];
	max->sz = i[3];
	max->min = i[5];
	max->maj = i[4];
	free(i);
	return (max);
}

void	find_maj_min(struct stat st, t_max *max)
{
	int		min;
	int		maj;
	char	*tmp;

	min = minor(st.st_rdev);
	maj = major(st.st_rdev);
	calc_esp(ft_intcount(maj), max, 6);
	tmp = ft_itoa(maj);
	ft_putstr(tmp);
	free(tmp);
	ft_putstr(", ");
	calc_esp(ft_intcount(min), max, 5);
	tmp = ft_itoa(min);
	ft_putstr(tmp);
	free(tmp);
}

void	maj_min_nor(struct stat st, t_max *max)
{
	static int i;

	if (S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode))
	{
		find_maj_min(st, max);
		i = -1;
	}
	else if (i == -1)
	{
		calc_esp(ft_intcount(st.st_size), max, 5);
		calc_esp(ft_intcount(st.st_size) - 3, max, 6);
		calc_esp(ft_intcount(st.st_size), max, 4);
		ft_putnbr((int)st.st_size);
	}
	else
	{
		calc_esp(ft_intcount(st.st_size), max, 4);
		ft_putnbr((int)st.st_size);
	}
}

void	ft_time(char **tab, struct stat st)
{
	char		*tabtime;
	time_t		now;
	char		*tab2;
	char		*tmp;

	tab2 = ft_strnew(0);
	now = time(NULL);
	if (now - st.st_mtime > 15778476)
	{
		tabtime = ctime(&st.st_mtime);
		ft_remplir(*tab, tabtime, 4, 9);
		ft_remplir(tab2, tabtime, 19, 23);
		tmp = tab2;
		tab2 = ft_strjoin(" ", tab2);
		free(tmp);
		ft_strcat(*tab, tab2);
		ft_putstr(*tab);
	}
	else
	{
		tabtime = ctime(&st.st_mtime);
		ft_remplir(*tab, tabtime, 4, 15);
		ft_putstr(*tab);
	}
	free(tab2);
}

void	print_usr(struct stat st, t_max *list)
{
	struct passwd	*usr;

	usr = getpwuid(st.st_uid);
	ft_putstr(usr->pw_name);
	calc_esp(ft_strlen(usr->pw_name), list, 2);
}
