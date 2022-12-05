/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:37 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/05 22:55:58 by mzoheir          ###   ########.fr       */
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
	char	**str;
	int		j;
	
	zeroing_data(&data);
	map = "maps/map.ber";
	data->fd = open(map, O_RDONLY);
	data->get = get_next_line(data->fd);
	i = 0;
	while (data->get != NULL)
	{
		free(data->get);
		data->get = get_next_line(data->fd);
		data->counter++;
		i++;
	}
	if(data->get == NULL)
		data->counter++;
	close(data->fd);
	data->fd = open(map, O_RDONLY);
	str = (char **)ft_calloc(i, sizeof(char *));
	j = 0;
	while (i-- >= 0)
		str[j++] = get_next_line(data->fd);
	str[j] = NULL;
	close(data->fd);
	return (str);
}

int validmap(char **str, t_str *data,char *map)
{
    str = ft_checkmap(map,&data);
	while(++str[data->i] != NULL)
	{
		while(str[data->i][++data->j] && ++data->i < data->counter)
    	{
        	if(ft_strchr("P01CE",str[data->i][data->j] == 1) && ft_strlen(str[data->i] = ft_strlen(str[0])) 
			&& (str[0][data->j] == '1' && str[data->counter -1][data->j] == '1') && str[1][0] == '1' && str[data->counter -2][0] == '1'
			&& str[1][ft_strlen(str[0])]== '1' && str[data->counter -2][ft_strlen(str[0])] == '1' && (data->counter -1) != ft_strlen(str[0])) 
					check_extra(str, &data);
			
				
			
    	}
	}
}


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

void	check_extra(char **str, t_str *data)
{
	if(str[data->i][data->j] = "E")
		data->exit++;
	if(str[data->i][data->j] = "C")
		data->coins++;
	if(str[data->i][data->j] = "P")
		data->player++;
}
int main()
{
	t_str data;
	char *map;
	
	data = *(t_str*)ft_calloc(1,sizeof(data));
	map = "maps/map.ber";
	ft_checkmap(map,&data);
	ft_printf("counter:%d\n", data.counter);
	ft_printf("i:%d\n", data.i);
	return(0);
}
