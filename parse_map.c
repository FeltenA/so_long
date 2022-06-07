/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:23:50 by afelten           #+#    #+#             */
/*   Updated: 2022/06/07 16:15:28 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_map(char *map, int width, int height)
{
	int	i;
	int	j;
	int	exit;
	int	start;
	int	coll;

	exit = 0;
	start = 0;
	coll = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if ((i == height || i == 0 || j == width || j == 0)
				&& map[i * width + j] != '1')
				return (0);
			if (map[i * width + j] == 'E')
				exit = 1;
			else if (map[i * width + j] == 'P')
				start = 1;
			else if (map[i * width + j] == 'C')
				coll = 1;
		}
	}
	return (exit && start && coll);
}

char	*parse_map(char *file)
{
	int		fd;
	char	*map;
	char	*save;
	int		size;

	fd = open(file, RD_ONLY);
	if (fd < 0)
		return (0);
	map = get_next_line(fd);
	size = ft_strlen(map);
	save = get_next_line(fd);
	while (save && ft_strlen(save) == size)
	{
		map = ft_strjoin_free(map, save);
		save = get_next_line(fd);
	}
	if (save)
	{
		free(save);
		free(map);
		return (0);
	}
	if (!check_map(map))
	{
		free(map);
		return (0);
	}
	return (map);
}
