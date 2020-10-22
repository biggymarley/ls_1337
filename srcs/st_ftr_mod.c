/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_ftr_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 23:53:08 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 03:54:34 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

int		filetype(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

char	*st_ftr_mod(int st_mode, char *buff)
{
	buff[0] = filetype(st_mode);
	buff[1] = ((st_mode & S_IRUSR) ? 'r' : '-');
	buff[2] = ((st_mode & S_IWUSR) ? 'w' : '-');
	buff[3] = ((st_mode & S_IXUSR) ? 'x' : '-');
	if (st_mode & S_ISUID)
		buff[3] = ((buff[3] == 'x') ? 's' : 'S');
	buff[4] = ((st_mode & S_IRGRP) ? 'r' : '-');
	buff[5] = ((st_mode & S_IWGRP) ? 'w' : '-');
	buff[6] = ((st_mode & S_IXGRP) ? 'x' : '-');
	if (st_mode & S_ISGID)
		buff[6] = ((buff[6] == 'x') ? 's' : 'S');
	buff[7] = ((st_mode & S_IROTH) ? 'r' : '-');
	buff[8] = ((st_mode & S_IWOTH) ? 'w' : '-');
	buff[9] = ((st_mode & S_IXOTH) ? 'x' : '-');
	if (st_mode & S_ISVTX)
		buff[9] = ((buff[9] == 'x') ? 't' : 'T');
	return (buff);
}
