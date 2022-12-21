/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:05:59 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/20 16:26:12 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	frame_exit(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] == 'E'
		&& data->coins_c == 0)
		exit_free(data);
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] == 'E'
		&& data->coins_c == 0)
		exit_free(data);
	if (key == 125 && data->map[((data->py) / 50) + 1][(data->px) / 50] == 'E'
		&& data->coins_c == 0)
		exit_free(data);
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px) / 50)] == 'E'
		&& data->coins_c == 0)
		exit_free(data);
}

void	infect_map(t_str *data, int i, int j)
{
	int	val;

	val = 0;
	i = 1;
	while (data->map_bis[i])
	{
		j = 1;
		while (data->map_bis[i][j])
		{
			if (data->map_bis[i][j] == 'P' && (data->map_bis[i + 1][j] == 'C'
					|| data->map_bis[i - 1][j] == 'C' || data->map_bis[i][j
					+ 1] == 'C' || data->map_bis[i][j - 1] == 'C'))
				data->coins_bis--;
			if (data->map_bis[i][j] == 'P' && (data->map_bis[i + 1][j] == 'E'
					|| data->map_bis[i - 1][j] == 'E' || data->map_bis[i][j
					+ 1] == 'E' || data->map_bis[i][j - 1] == 'E'))
				data->exit_bis--;
			val += infect_bis(data, i, j);
			j++;
		}
		i++;
	}
	if (val > 0)
		infect_map(data, 0, 0);
}

int	infect_bis(t_str *data, int i, int j)
{
	int	res;

	res = 0;
	infectos(data, &res, i, j);
	if (data->map_bis[i][j] == 'P' && data->map_bis[i][j + 1] != '1'
		&& data->map_bis[i][j + 1] != 'P')
	{
		data->map_bis[i][j + 1] = 'P';
		res = 1;
	}
	if (data->map_bis[i][j] == 'P' && data->map_bis[i][j - 1] != '1'
		&& data->map_bis[i][j - 1] != 'P')
	{
		data->map_bis[i][j - 1] = 'P';
		res = 1;
	}
	return (res);
}

int	valid_bis(t_str *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("EC", data->map_bis[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_path(t_str *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	infect_map(data, i, j);
	if (valid_bis(data))
		return (1);
	return (0);
}
