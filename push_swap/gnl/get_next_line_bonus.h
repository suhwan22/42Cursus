/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:56:51 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 21:01:57 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*pre;
	char			*str;
	int				fd;
}	t_list;

char		*ft_strchr_bonus(const char *s, int c);
char		*ft_strdup_bonus(char *s);
char		*ft_strjoin_bonus(char *s1, char *s2);
void		ft_strlcpy_bonus(char *dst, char *src, size_t dstsize);
void		lst_del_bonus(t_list *lst);
int			ft_strncmp_bonus(const char *s1, const char *s2, size_t n);

long long	ft_strtol_bonus(char *str);
int			ft_atoi_bonus(const char *str);

t_list		*check_fd(t_list *head, int fd);
char		*get_next_line(int fd);
char		*get_one_line(char *str);
char		*read_fd(t_list *node);
char		*remain_line(t_list *node);

#endif
