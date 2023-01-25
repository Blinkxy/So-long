/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:37 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 19:54:07 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valid_mapfile(char *map)
{
	int		fd;
	char	*ext;
	int		len;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Map file invalid or not found !\n");
		return (0);
	}
	ext = ft_strnstr(map, ".ber", ft_strlen(map));
	if (!ext)
		return (0);
	len = ft_strlen(ext);
	if (ext && ft_strncmp(ext, ".ber", len) == 0 && ext[len - 1] == 'r'
		&& ext[len - 2] == 'e' && ext[len - 3] == 'b' && ext[len - 4] == '.')
		return (1);
	close(fd);
	return (0);
}

void	ft_checkmap(char *str, t_str *data)
{
	int	i;
	int	j;

	data->fd = open(str, O_RDONLY);
	data->get = get_next_line(data->fd);
	i = 0;
	while (data->get != NULL)
	{
		free(data->get);
		data->get = get_next_line(data->fd);
		data->counter++;
		i++;
	}
	if (data->get == NULL)
		data->counter++;
	close(data->fd);
	data->fd = open(str, O_RDONLY);
	data->map = (char **)ft_calloc(data->counter, sizeof(char *));
	j = 0;
	while (i-- >= 0)
		data->map[j++] = get_next_line(data->fd);
	data->map[j] = NULL;
	close(data->fd);
}

void	ft_checkmap_bis(char *str, t_str *data)
{
	int	i;
	int	j;

	data->fd = open(str, O_RDONLY);
	data->get = get_next_line(data->fd);
	i = 0;
	while (data->get != NULL)
	{
		free(data->get);
		data->get = get_next_line(data->fd);
		i++;
	}
	close(data->fd);
	data->fd = open(str, O_RDONLY);
	data->map_bis = (char **)ft_calloc(data->counter, sizeof(char *));
	j = 0;
	while (i-- >= 0)
		data->map_bis[j++] = get_next_line(data->fd);
	data->map_bis[j] = NULL;
	close(data->fd);
}

int	validmap(t_str *data)
{
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (ft_strchr("P01CEX", data->map[data->i][data->j]) == 0)
				return (0);
			if (ft_strlen(data->map[data->i]) != ft_strlen(data->map[0]))
				return (0);
			if (data->map[0][data->j] != '1'
			|| data->map[(data->counter) - 2][data->j] != '1')
				return (0);
			if (data->map[data->counter] != 0)
				return (0);
			if (data->map[data->i][0] != '1'
				|| data->map[data->i][ft_strlen(data->map[data->i]) - 1] != '1')
				return (0);
			check_extra(data);
			data->j++;
		}
		data->i++;
	}
	if (data->exit_c == 1 && data->player_c == 1 && data->coins_c >= 1)
		return (1);
	return (0);
}

void	mlx_looping(t_str *data)
{
	mlx_hook(data->win, 2, 0, escape_key, data);
	mlx_hook(data->win, 17, 0, x_close, data);
	mlx_key_hook(data->win, move_player, data);
	mlx_loop_hook(data->mlx, enemy_moves, data);
	mlx_loop(data->mlx);
}
