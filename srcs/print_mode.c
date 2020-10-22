/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:13:09 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:20:51 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	print_grp(struct stat st, t_max *list)
{
	struct group *grp;

	grp = getgrgid(st.st_gid);
	ft_putstr(grp->gr_name);
	calc_esp(ft_strlen(grp->gr_name), list, 3);
}

void	size_and_time(char **tab, t_max *list, struct stat st)
{
	maj_min_nor(st, list);
	ft_putchar(' ');
	ft_time(tab, st);
	ft_putchar(' ');
}

void	printer(t_list *ftab, t_max *list, char **tab, unsigned short op)
{
	char *buff;

	buff = (char*)ft_memalloc(sizeof(char) * 11);
	st_ftr_mod(ftab->st.st_mode, buff);
	ft_putstr(buff);
	ft_ex_finder(ftab);
	calc_esp(ft_intcount(ftab->st.st_nlink), list, 1);
	ft_putnbr(ftab->st.st_nlink);
	ft_putchar(' ');
	if (!(op & G))
		print_usr(ftab->st, list);
	print_grp(ftab->st, list);
	size_and_time(tab, list, ftab->st);
	if (op & GG)
		ft_colors(ftab);
	if (S_ISLNK(ftab->st.st_mode))
		ft_link_printer(ftab);
	else
		ft_putstr(ftab->content);
	ft_putendl("\e[0m");
	ft_bzero((void*)buff, 11);
	free(buff);
}

void	printl(t_list *ftab, unsigned short op)
{
	char			*tab;
	t_max			*list;

	tab = (char *)ft_memalloc(sizeof(char) * 1);
	list = checker(&ftab);
	while (ftab->content != NULL)
	{
		printer(ftab, list, &tab, op);
		ftab = ftab->next;
	}
	ft_del_max(&list);
	free(list);
	free(tab);
}

void	print_mode(t_list *ftab, unsigned short op, int total)
{
	if (op & L || op & G)
	{
		if (ftab->content == NULL)
			total = -1;
		if (total >= 0)
		{
			ft_putstr("total ");
			ft_putnbr(total);
			ft_putchar('\n');
		}
		printl(ftab, op);
	}
	else
	{
		while (ftab->content != NULL)
		{
			if (op & GG)
				ft_colors(ftab);
			ft_putstr(ftab->content);
			ft_putendl("\033[0m");
			ftab = ftab->next;
		}
	}
}
