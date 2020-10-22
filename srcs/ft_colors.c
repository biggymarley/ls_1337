/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:58:52 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 02:35:22 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

int			ft_all_perm(struct stat st)
{
	if ((S_IRUSR & st.st_mode) && (S_IWUSR & st.st_mode)
			&& (S_IXUSR & st.st_mode))
	{
		if ((S_IRGRP & st.st_mode) && (S_IWGRP & st.st_mode)
				&& (S_IXGRP & st.st_mode))
		{
			if ((S_IROTH & st.st_mode) && (S_IWOTH & st.st_mode)
				&& (S_IXOTH & st.st_mode))
				return (1);
		}
		return (0);
	}
	return (0);
}

int			bit_colors(struct stat st)
{
	if ((st.st_mode & S_ISUID || st.st_mode & S_ISGID
				|| st.st_mode & S_ISVTX) && S_ISDIR(st.st_mode))
	{
		ft_putstr("\033[30;48;5;10m");
		return (1);
	}
	else if (st.st_mode & S_ISUID || st.st_mode & S_ISGID
				|| st.st_mode & S_ISVTX)
	{
		ft_putstr("\033[30;48;5;1m");
		return (1);
	}
	return (0);
}

void		ft_colors(t_list *list)
{
	if (bit_colors(list->st))
		return ;
	else if (ft_all_perm(list->st))
		ft_putstr("\033[30;48;5;11m");
	else if (S_ISDIR(list->st.st_mode))
		ft_putstr("\033[1;36m");
	else if (S_ISFIFO(list->st.st_mode))
		ft_putstr("\033[33m");
	else if (S_ISLNK(list->st.st_mode))
		ft_putstr("\033[35m");
	else if (S_ISSOCK(list->st.st_mode))
		ft_putstr("\033[32m");
	else if (S_ISBLK(list->st.st_mode) || S_ISCHR(list->st.st_mode))
		ft_putstr("\e[48;5;11m\e[34m");
	else if ((S_IXUSR & list->st.st_mode) || (S_IXGRP & list->st.st_mode)
				|| (S_IXOTH & list->st.st_mode))
		ft_putstr("\033[31m");
}
