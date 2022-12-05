/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:25 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/05 20:51:56 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BASE_LOW "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct So_long
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	void	*coins;
	void	*exit;
	int		img_width;
	int		img_height;
	char	*path1;
	char	*path2;
	int 	i;
	int		j;
	int 	counter;
	void  	*get;
	int		fd;
}			t_str;

char		**ft_split(char *s, char c);
char		*ft_itoa(int n);
int			ft_putchar(char c);
int			ft_printf(const char *s, ...);
int			ft_putstr(char *s);
int			ft_strlen(char *s);
int			ft_putnbr(long n);
int			ft_putnbrhex(unsigned long b, char *base);
int			ft_argprint(va_list p, char c);
int			ft_unsigned(unsigned int k);
char		*ft_read_and_join(int fd, char *stash);
char		*save_rest(char *stash);
char		*get_each_line(char *stash);
char		*get_next_line(int fd);
char		*ft_substr(char *s, int start, int len);
int			ft_strchr(char *s, char c);
char		*ft_calloc(int count, int size);
void		ft_bzero(char *s, int n);
char		*ft_strjoin(char *s1, char *s2, int k, int l);
char		*ft_strdup(char *s1);
char		**ft_checkmap(char *map, t_str *data);
int 		validmap(char **str, t_str *data,char *map);
void		zeroing_data(t_str *data);
void		check_extra(char **str, t_str *data);

#endif
