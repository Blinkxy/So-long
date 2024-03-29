/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:02:25 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:10:49 by mzoheir          ###   ########.fr       */
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
	void	*dirt;
	void	*player;
	void	*coins;
	void	*enemy;
	int		exit_c;
	int		exit_bis;
	int		player_c;
	int		coins_c;
	int		coins_bis;
	void	*exit;
	void	*grass;
	int		img_width;
	int		img_height;
	char	*path_player;
	char	*path_wall;
	char	*path_coins;
	char	*path_exit;
	char	*path_dirt;
	char	*path_enemy;
	int		i;
	int		j;
	int		virus;
	int		counter;
	void	*get;
	int		fd;
	int		x;
	int		y;
	char	**map;
	char	**map_bis;
	int		py;
	int		px;
	int		moves;
	int		ey;
	int		ex;
}			t_str;

char		**ft_split(char *s, char c);
char		*ft_itoa(int n);
int			ft_putchar(char c);
int			ft_printf(const char *s, ...);
int			ft_putstr(char *s);
void		first_frame(t_str *data);
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
int			validmap(t_str *data);
void		zeroing_data(t_str *data);
void		check_extra(t_str *data);
char		*ft_strnstr(char *haystack, char *needle, int len);
int			valid_mapfile(char *map);
int			ft_strncmp(char *s1, char *s2, int n);
int			x_close(t_str *data);
int			escape_key(int key, t_str *data);
void		mlx_looping(t_str *data);
void		frame_check(t_str *data);
void		move_right(t_str *data);
void		move_bot(t_str *data);
void		move_top(t_str *data);
void		move_left(t_str *data);
void		ft_checkmap(char *str, t_str *data);
int			move_player(int key, t_str *data);
void		move_to_wall(int key, t_str *data);
void		frame_coins(int key, t_str *data);
void		frame_exit(int key, t_str *data);
void		frame_all(int key, t_str *data);
void		init_mlx(t_str *data);
void		move_sub(int key, t_str *data);
void		f_check_sub(t_str *data);
int			valid_path(t_str *data);
void		infect_map(t_str *data, int i, int j);
int			infect_map_exit(t_str *data, int i, int j);
int			valid_bis(t_str *data);
int			infect_bis(t_str *data, int i, int j);
int			exit_free(t_str *data);
void		ft_checkmap_bis(char *str, t_str *data);
void		infectos(t_str *data, int *res, int i, int j);
void		frame_bis(t_str *data, int i, int j);
#endif
