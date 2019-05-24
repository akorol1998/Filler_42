/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:59:44 by akorol            #+#    #+#             */
/*   Updated: 2019/05/22 14:59:47 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			reading_map(t_filler *my_t)
{
	char		**tab;
	char		*line;
	size_t		a;
	int			i;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * my_t->map_row + 1);
	tab[my_t->map_row] = NULL;
	a = get_next_line(0, &line);
	free(line);
	while (++i < my_t->map_row)
	{
		get_next_line(0, &line);
		tab[i] = ft_strsub(line, 4, my_t->map_col);
		free(line);
	}
	my_t->map = tab;
	my_t->valid_x = (int*)malloc(sizeof(int) * my_t->map_row * my_t->map_col);
	my_t->valid_y = (int*)malloc(sizeof(int) * my_t->map_row * my_t->map_col);
}

void			fill_token_xy(char **tab, t_filler *my_t)
{
	int			i;
	int			j;
	int			k;

	my_t->tok_x = (int*)malloc(sizeof(int) * my_t->count);
	my_t->tok_y = (int*)malloc(sizeof(int) * my_t->count);
	i = -1;
	k = 0;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '*')
			{
				my_t->tok_x[k] = i;
				my_t->tok_y[k] = j;
				k++;
			}
			j++;
		}
	}
}

void			token_coordinates(char **tab, t_filler *my_t)
{
	int			i;

	fill_token_xy(tab, my_t);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void			reading_token(t_filler *my_t)
{
	char		**tab;
	char		*line;
	int			i;
	int			j;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * my_t->tok_row + 1);
	tab[my_t->tok_row] = NULL;
	my_t->count = 0;
	while (++i < my_t->tok_row)
	{
		j = -1;
		get_next_line(0, &line);
		tab[i] = ft_strdup(line);
		while (tab[i][++j])
		{
			if (tab[i][j] == '*')
				my_t->count++;
		}
		free(line);
	}
	token_coordinates(tab, my_t);
}
