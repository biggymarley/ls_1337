/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:45:43 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/23 00:49:14 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	op_checker(int *i, unsigned short *op, char **av)
{
	while (av[*i] && (av[*i][0] == '-' && av[*i][1] != '\0'))
	{
		if (!(add_option(op, av[*i])))
		{
			*i += 1;
			break ;
		}
		*i += 1;
	}
}

void	op_and_args(unsigned short op, char **av, int i, t_list **files)
{
	struct stat	st;
	char		*buff;
	int			total;
	char		*str;

	total = -1;
	buff = ft_strnew(4096);
	lstat(av[i], &st);
	if (S_ISLNK(st.st_mode) && !(op & L) && !(op & G))
		ft_linkdir(av[i], buff, op);
	else if (S_ISDIR(st.st_mode))
		read_file(av[i], op);
	else
	{
		str = ft_args_adder(av, i, op, files);
		all_in(files, op, &str, total);
	}
	free(buff);
}

void	norm2lines(char **av, int i, unsigned short op, t_list **files)
{
	char	*str;
	int		total;

	total = -1;
	str = ft_args_adder(av, i, op, files);
	all_in(files, op, &str, total);
}

void	nread(char **av, int i)
{
	char		*str;
	char		**s;
	struct stat	st;

	str = ft_strnew(0);
	while (av[i])
	{
		if ((lstat(av[i], &st)))
			adder(&str, av[i]);
		i++;
	}
	s = ft_strsplit(str, ':');
	free(str);
	ft_sort_tab(s);
	i = 0;
	while (s[i])
		ft_errors(s[i++]);
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int		main(int ac, char **av)
{
	int				i;
	unsigned short	op;
	struct stat		st;
	t_list			*files;

	lstat(NULL, &st);
	files = ft_newlst(NULL, 0, st, NULL);
	i = 1;
	if (ac == 1)
		if (one_ag(&files, 0))
			return (0);
	op_checker(&i, &op, av);
	nread(av, i);
	if (i == ac && !(op & D))
		if (one_ag(&files, op))
			return (0);
	if (ac == (i + 1) && !(op & D))
		op_and_args(op, av, i, &files);
	else
		norm2lines(av, i, op, &files);
	ft_deletlist(&files, func);
	return (0);
}
