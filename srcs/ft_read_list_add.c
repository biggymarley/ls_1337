/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_list_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 04:55:31 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 05:33:29 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

void	adder2(char **str, char *av, char **tmp)
{
	char *tmp2;

	tmp2 = *str;
	*str = ft_strjoin(*str, av);
	free(tmp2);
	tmp2 = *str;
	*str = ft_strjoin(*str, ":");
	free(tmp2);
	ft_strdel(tmp);
}

void	ft_path_joint(char **buff, char *path, char *s)
{
	char *tmp2;

	tmp2 = *buff;
	*buff = ft_strjoin(path, "/");
	free(tmp2);
	tmp2 = *buff;
	*buff = ft_strjoin(*buff, s);
	free(tmp2);
}

int		function(char **buff, t_list **ftab, char *s, int *total)
{
	struct stat	st;
	t_list		*ftab2;

	if (lstat(*buff, &st) == -1)
		return (0);
	else
	{
		*total += st.st_blocks;
		ftab2 = ft_newlst(s, ft_strlen(s), st, *buff);
		ft_strclr(*buff);
		ft_lstadd(ftab, ftab2);
		return (1);
	}
}

char	*ft_read_list_add(DIR *dirp, char *path, t_var var, t_list **ftab)
{
	struct dirent	*drt;
	char			*tmp;
	char			*buff;
	char			*str;

	buff = (char*)ft_memalloc(sizeof(char));
	str = ft_strnew(0);
	while ((drt = readdir(dirp)))
	{
		if (!(var.op & D) && (var.op & RR)
				&& (tmp = is_directory(path, drt->d_name, var.op)))
			adder2(&str, tmp, &tmp);
		if (drt->d_name[0] != '.' || (var.op & A) || (var.op & F))
		{
			ft_path_joint(&buff, path, drt->d_name);
			if (!(function(&buff, ftab, drt->d_name, var.total)))
				continue;
		}
	}
	free(buff);
	return (str);
}
