/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:15:52 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:35:41 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	func(void *s, size_t n, void *str)
{
	n = 0;
	free(s);
	free(str);
}

void	all_in(t_list **files, unsigned short op, char **str, int total)
{
	char **s;

	sorting(files, op);
	print_mode(*files, op, total);
	s = ft_strsplit(*str, ':');
	if (s[0] && (*files)->content)
		ft_putchar('\n');
	free(*str);
	if (!(op & F))
		ft_sort_tab(s);
	ft_ls(op, s);
}

void	read_file(char *path, unsigned short op)
{
	t_read	read;
	t_var	var;
	int		total;

	if (!(read.dirp = opendir(path)))
	{
		ft_errors(path);
		return ;
	}
	total = 0;
	var.total = &total;
	var.op = op;
	read.ftab = ft_newlst(NULL, 0, read.st, NULL);
	read.str = ft_read_list_add(read.dirp, path, var, &read.ftab);
	closedir(read.dirp);
	all_in(&read.ftab, op, &read.str, *var.total);
	ft_deletlist(&read.ftab, func);
}
