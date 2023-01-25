/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:49:41 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 19:36:14 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_and_join(int fd, char *stash)
{
	char	*buffer;
	int		c_read;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	c_read = 1;
	while (c_read != 0 && ft_strchr(stash, '\n') == 0)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer, i, j);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 1 || fd == 1 || fd == 2)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	stash = ft_read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = get_each_line(stash);
	stash = save_rest(stash);
	return (line);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_calloc(int count, int size)
{
	char	*str;
	int		t;

	t = count * size;
	str = (char *)malloc(t);
	if (!str)
		return (NULL);
	ft_bzero(str, t);
	return (str);
}

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

// int main()
// {
//     int fd;
// 	// char *filename = "yo.txt";
//     fd = open(, O_RDONLY | O_CREAT);
//   printf("%s", get_next_line(fd));
//   int	fd1 = open("yo.txt", O_RDONLY | O_CREAT);

//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd1));

// }
//
// }
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));

// }

// }
// //     // write(1,"hello",5);
// // }
