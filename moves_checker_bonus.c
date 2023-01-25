/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:05:59 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 19:35:03 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		&& data->map_bis[i][j + 1] != 'P' && data->map_bis[i][j + 1] != 'X')
	{
		data->map_bis[i][j + 1] = 'P';
		res = 1;
	}
	if (data->map_bis[i][j] == 'P' && data->map_bis[i][j - 1] != '1'
		&& data->map_bis[i][j - 1] != 'P' && data->map_bis[i][j - 1] != 'X')
	{
		data->map_bis[i][j - 1] = 'P';
		res = 1;
	}
	return (res);
}

void	infectos(t_str *data, int *res, int i, int j)
{
	if (data->map_bis[i][j] == 'P' && data->map_bis[i + 1][j] != '1'
		&& data->map_bis[i + 1][j] != 'P' && data->map_bis[i + 1][j] != 'X')
	{
		data->map_bis[i + 1][j] = 'P';
		*res = 1;
	}
	if (data->map_bis[i][j] == 'P' && data->map_bis[i - 1][j] != '1'
		&& data->map_bis[i - 1][j] != 'P' && data->map_bis[i - 1][j] != 'X')
	{
		data->map_bis[i - 1][j] = 'P';
		*res = 1;
	}
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
