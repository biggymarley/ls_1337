/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:19:54 by afaragi           #+#    #+#             */
/*   Updated: 2019/12/22 05:33:13 by afaragi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft/libft.h"
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>

# define L	1
# define RR	2
# define A	4
# define R	8
# define T	16
# define G	32
# define GG	64
# define F	128
# define D	256

typedef struct		s_read
{
	char			**tab;
	char			*str;
	char			*ptmp;
	int				i;
	int				c;
	int				j;
	char			*buff;
	struct stat		st;
	char			**dir;
	struct stat		st1;
	char			*tmp;
	char			*tmp2;
	t_list			*ftab;
	t_list			*ftab2;
	struct dirent	*drt;
	DIR				*dirp;
}					t_read;

typedef struct		s_vars
{
	struct stat		st;
	char			*str;
	t_list			*list;
	char			*buff;
}					t_vars;

typedef struct		s_var
{
	int				*total;
	int				op;
}					t_var;

typedef struct		s_max
{
	int				li;
	int				us;
	int				gr;
	int				sz;
	int				min;
	int				maj;
}					t_max;

void				sorting(t_list **lst, unsigned short op);
int					add_option(unsigned short *op, char *arg);
char				*is_directory(char *path, char *name, unsigned short op);
void				print_mode(t_list *ftab, unsigned short op, int total);
void				ft_sort_tab_time(char **tab);
int					rev_tab(char **tab);
void				read_file(char *path, unsigned short op);
void				rec_r(char **tab, unsigned short op);
void				rec_rr(char **tab, unsigned short op);
char				*ft_read_list_add(DIR *dirp, char *path,
					t_var var, t_list **ftab);
void				ft_sort_tab(char **tab);
void				ft_ls(unsigned short op, char **s);
char				*ft_args_adder(char **av, int i,
					unsigned short op, t_list **files);
void				print_file(char *file, struct stat st);
void				espaces(int num);
void				func(void *s, size_t n, void *str);
void				ft_colors(t_list *list);
void				ft_link_printer(t_list *list);
char				*st_ftr_mod(int st_mode, char *buff);
void				ft_strjoinfirst(char const *s1, char s2, char	**str);
void				ft_linkdir(char *path, char *buff, unsigned short op);
void				ft_sort_tab_f(char **tab);
void				ft_errors(char *av);
void				adder(char **str, char *av);
void				all_in(t_list **files, unsigned short op,
					char **str, int total);
void				ft_ex_finder(t_list *list);
void				ft_del_max(t_max **list);
void				calc_esp(int num, t_max *max, int c);
void				espaces(int num);
void				ft_maj_min_check(int *maj, int *min, t_list *list);
void				ft_max_finder(t_list *list, int *i);
t_max				*checker(t_list **ftab);
void				find_maj_min(struct stat st, t_max *max);
void				maj_min_nor(struct stat st, t_max *max);
void				ft_time(char **tab, struct stat st);
void				print_usr(struct stat st, t_max *list);
void				ft_swap(t_list *c, t_list *b);
void				sort_time(t_list **lst);
void				ft_linkdir(char *path, char *buff, unsigned short op);
int					one_ag(t_list **files, unsigned short op);
#endif
