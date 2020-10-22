/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_print_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 02:11:34 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:20:10 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	ft_del_max(t_max **list)
{
	(*list)->li = 0;
	(*list)->us = 0;
	(*list)->gr = 0;
	(*list)->sz = 0;
	(*list)->min = 0;
	(*list)->maj = 0;
}

void	calc_esp(int num, t_max *max, int c)
{
	if (c == 1)
		espaces((max->li - num) + 1);
	if (c == 2)
		espaces((max->us - num) + 2);
	if (c == 3)
		espaces((max->gr - num) + 2);
	if (c == 4)
		espaces((max->sz - num));
	if (max->maj != 0)
	{
		if (c == 5)
			espaces((max->min - num));
		if (c == 6)
			espaces((max->maj - num));
	}
	return ;
}

void	espaces(int num)
{
	while (num > 0)
	{
		ft_putchar(' ');
		num--;
	}
}

void	ft_maj_min_check(int *maj, int *min, t_list *list)
{
	if (*maj < ft_intcount(major(list->st.st_rdev)))
		*maj = ft_intcount(major(list->st.st_rdev));
	if (*min < ft_intcount(minor(list->st.st_rdev)))
		*min = ft_intcount(minor(list->st.st_rdev));
}

void	ft_max_finder(t_list *list, int *i)
{
	struct passwd	*usr;
	struct group	*grp;

	if (i[0] < ft_intcount(list->st.st_nlink))
		i[0] = ft_intcount(list->st.st_nlink);
	usr = getpwuid(list->st.st_uid);
	if (i[1] < (int)ft_strlen(usr->pw_name))
		i[1] = ft_strlen(usr->pw_name);
	grp = getgrgid(list->st.st_gid);
	if (i[2] < (int)ft_strlen(grp->gr_name))
		i[2] = ft_strlen(grp->gr_name);
	if (S_ISBLK(list->st.st_mode) || S_ISCHR(list->st.st_mode))
		ft_maj_min_check(&i[4], &i[5], list);
	else if (i[3] < ft_intcount(list->st.st_size))
		i[3] = ft_intcount(list->st.st_size);
}
