/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:37 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/05 17:36:27 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

// void	ft_error(int validmap())
// {
	
// 	stderr(1);
	
// }



char	**ft_checkmap(char *map, t_str *data)
{
	int		i;
	int		fd;
	char	**str;
	int		j;
	char  	*get;
	
	map = "maps/map.ber";
	fd = open(map, O_RDONLY);
	get = get_next_line(fd);
	i = 0;
	while (get != NULL)
	{
		free(get);
		get = get_next_line(fd);
		data->counter++;
		i++;
	}
	if(get == NULL)
		data->counter++;
	close(fd);
	fd = open(map, O_RDONLY);
	str = (char **)ft_calloc(i, sizeof(char *));
	j = 0;
	while (data->i-- >= 0)
		str[j++] = get_next_line(fd);
	return (str);
}

// int validmap(char **str, t_str *data,char *map)
// {
// 	zeroing_data(&data);
//     str = ft_checkmap(map,&data);
// 	while(++str[data->i] != NULL)
// 	{
// 		while(str[data->i][++data->j] && data->i < data->counter)
//     	{
//         	if(ft_strchr("P0C1E",str[data->i][data->j] == 0) || ft_strlen(str[data->i]))
//         return(0);
//     	}



// }


void	zeroing_data(t_str *data)
{
	data->coins = 0;
	data->player = 0;
	data->wall = 0;
	data->i = -1;
	data->j = -1;
	data->exit = 0;
	data->counter = 0;
}


int main()
{
	t_str data;
	char *map;
	
	data = *(t_str*)ft_calloc(1,sizeof(data));
	map = "maps/map.ber";
	ft_checkmap(map,&data);
	ft_printf("%d", data.counter);
	return(0);
}
