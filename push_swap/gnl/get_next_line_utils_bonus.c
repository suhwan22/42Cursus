/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:50:33 by suhkim            #+#    #+#             */
/*   Updated: 2022/11/13 20:57:50 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_bonus(const char *s, int c)
{
	const char	*sptr;
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	sptr = s;
	if (c == 0)
		return ((char *)sptr + len);
	while (*sptr)
	{
		if (*(char *)sptr == (char)c)
			return ((char *)sptr);
		sptr++;
	}
	return (0);
}

char	*ft_strdup_bonus(char *s)
{
	size_t	len;
	char	*str;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy_bonus(str, s, len + 1);
	return (str);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup_bonus(s2));
	s1_len = 0;
	while (s1 && *(s1 + s1_len))
		s1_len++;
	s2_len = 0;
	while (*(s2 + s2_len))
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	ft_strlcpy_bonus(str, s1, s1_len + 1);
	ft_strlcpy_bonus(str + s1_len, s2, s2_len + 1);
	free(s1);
	return (str);
}

void	ft_strlcpy_bonus(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (*(src + len))
		len++;
	i = 0;
	if (dstsize == 0)
		return ;
	while (*(src + i) != '\0')
	{
		if (i == dstsize - 1)
			break ;
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

void	lst_del_bonus(t_list	*lst)
{	
	lst->pre->next = lst->next;
	if (lst->next)
		lst->next->pre = lst->pre;
	free(lst);
}
