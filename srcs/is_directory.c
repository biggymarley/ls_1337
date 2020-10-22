/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:10:55 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 05:34:21 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"

char	*is_directory(char *path, char *name, unsigned short op)
{
	char		str[10000];
	struct stat	st;

	if (((!ft_strcmp("..", name) || (name[0] == '.' && name[1] == '\0'))))
		return (NULL);
	if (!(op & A) && (name[0] == '.' && name[1] != '\0') && !(op & F))
		return (NULL);
	ft_bzero((void*)str, 10000);
	ft_strcpy(str, path);
	if ((ft_strcmp(path, "/")) != 0)
		ft_strcat(str, "/");
	ft_strcat(str, name);
	lstat(str, &st);
	if (S_ISDIR(st.st_mode))
		return (ft_strdup(str));
	return (NULL);
}
