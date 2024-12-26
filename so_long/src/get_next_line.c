/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:32:07 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/07 02:32:26 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 100

char	*return_left(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	if (!(*backup))
		return (NULL);
	while (backup[i] != '\n' && backup[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*return_right(char *backup)
{
	char	*backup_right;
	int		backup_len;
	int		backup_left_len;
	int		i;

	backup_len = ft_strlen(backup);
	backup_left_len = 0;
	i = 0;
	while (backup[backup_left_len] != '\n' && backup[backup_left_len])
		backup_left_len++;
	if (backup[backup_left_len] == 0)
	{
		free(backup);
		return (NULL);
	}
	if (backup[backup_left_len] == '\n')
		backup_left_len++;
	backup_right = (char *) malloc(backup_len - backup_left_len + 1);
	if (!backup_right)
		return (NULL);
	while (backup[backup_left_len])
		backup_right[i++] = backup[backup_left_len++];
	backup_right[i] = '\0';
	free (backup);
	return (backup_right);
}

char	*read_line(int fd, char *backup)
{
	char	*temp;
	int		rb;

	rb = 1;
	temp = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (rb > 0 && !ft_strchr(backup, '\n'))
	{
		rb = read(fd, temp, BUFFER_SIZE);
		if (rb == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[rb] = '\0';
		backup = ft_strjoin(backup, temp);
	}
	free (temp);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_line(fd, backup);
	if (!backup)
		return (NULL);
	buffer = return_left(backup);
	backup = return_right(backup);
	return (buffer);
}
