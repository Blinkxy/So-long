/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infect_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:52:35 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/20 16:25:03 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	infectos(t_str *data, int *res, int i, int j)
{
	if (data->map_bis[i][j] == 'P' && data->map_bis[i + 1][j] != '1'
		&& data->map_bis[i + 1][j] != 'P')
	{
		data->map_bis[i + 1][j] = 'P';
		*res = 1;
	}
	if (data->map_bis[i][j] == 'P' && data->map_bis[i - 1][j] != '1'
		&& data->map_bis[i - 1][j] != 'P')
	{
		data->map_bis[i - 1][j] = 'P';
		*res = 1;
	}
}
