/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:43:25 by akorol            #+#    #+#             */
/*   Updated: 2019/05/21 16:43:27 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			search_for_sign(t_filler *my_t, char **line)
{
	if (!ft_strcmp(*line, "$$$ exec p1 : [./akorol.filler]"))
		my_t->sign = 'O';
	if (!ft_strcmp(*line, "$$$ exec p2 : [./akorol.filler]"))
		my_t->sign = 'X';
	free(*line);
}

void			read_figure(char *line, char **tab, t_filler *my_t)
{
	if (line[1] == 'l')
	{
		my_t->map_row = ft_atoi(tab[0]);
		my_t->map_col = ft_atoi(tab[1]);
		reading_map(my_t);
	}
	else if (line[1] == 'i')
	{
		my_t->tok_row = ft_atoi(tab[0]);
		my_t->tok_col = ft_atoi(tab[1]);
		reading_token(my_t);
	}
}

void			read_size(t_filler *my_t, char *line)
{
	char		*str;
	char		**tab;

	if (line[1] == 'l')
	{
		if (line[10] == '0')
			str = ft_strsub(line, 8, 6);
		else
			str = ft_strsub(line, 8, 5);
	}
	else
		str = ft_strsub(line, 6, 5);
	tab = ft_strsplit(str, ' ');
	read_figure(line, tab, my_t);
	free(tab[0]);
	free(tab[1]);
	free(tab);
	free(str);
}

void			read_vm(t_filler *my_t)
{
	size_t		a;
	char		*line;

	line = NULL;
	a = get_next_line(0, &line);
	search_for_sign(my_t, &line);
	while ((a = get_next_line(0, &line)))
	{
		if (ft_strlen(line) >= 7 && line[0] == 'P')
		{
			read_size(my_t, line);
			if (line[1] == 'i')
			{
				if (!setting_up_token(my_t))
					break ;
			}
			free(line);
			line = NULL;
		}
		if (line)
			free(line);
	}
	free(line);
}

int				main(void)
{
	t_filler	*my_t;

	my_t = (t_filler*)malloc(sizeof(t_filler));
	make_structure(my_t);
	read_vm(my_t);
	free(my_t);
	system("leaks akorol.filler > file.txt");
	return (0);
}
