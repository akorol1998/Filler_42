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

void		search_for_sign(t_filler *my_t, char *line)
{
	if (!ft_strcmp(line, "$$$ exec p1 : [./akorol.filler]"))
	{
		my_t->sign = 'O';
		ft_putstr_fd(line, g_fd);
	}
	if (!ft_strcmp(line, "$$$ exec p2 : [./akorol.filler]"))
	{
		ft_putstr_fd(line, g_fd);
		my_t->sign = 'X';
	}
	ft_putstr_fd("\n", g_fd);
	free(line);
}

void			read_size(t_filler *my_t, char *line)
{
	char		*str;
	char		**tab;

	if (line[1] == 'l')
		str = ft_strsub(line, 8, 5);
	else
		str = ft_strsub(line, 6, 5);
	tab = ft_strsplit(str, ' ');
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
		ft_putnbr_fd(my_t->tok_row, g_fd);
		ft_putnbr_fd(my_t->tok_col, g_fd);
		reading_token(my_t);
	}
	free(tab[0]);
	free(tab[1]);
	free(tab);
	free(str);
	free(line);
}

void			read_vm(t_filler *my_t)
{
	t_filler	*stuff;
	size_t		a;
	int			iter;
	char		*line;
	int			start;

	line = NULL;	
	iter = 0;
	g_fd = open("text.txt",O_RDWR | O_TRUNC);
	while ((a = get_next_line(0, &line)))
	{
		iter++;
		ft_putstr_fd(line, g_fd);
		ft_putstr_fd("\n", g_fd);
		if (iter == 1)
			search_for_sign(my_t, line);
		else if (ft_strlen(line) >= 7 && line[0] == 'P')
		{
			read_size(my_t, line);
			if (line[1] == 'i')
			{
				if (!setting_up_token(my_t))
					break;
			}
		}
	}
}

void	make_structure(t_filler *my_t)
{
	// my_t->tok = NULL;
	my_t->map = NULL;
	my_t->sign = 0;
	my_t->map_row = 0;
	my_t->map_col = 0;
	my_t->tok_row = 0;
	my_t->tok_col = 0;
	my_t->tok_x = NULL;
	my_t->tok_y = NULL;
	my_t->valid_x = NULL;
	my_t->valid_y = NULL;
	my_t->x_cor = 0;
	my_t->y_cor = 0;
	my_t->head = 0;
}

int main()
{
	t_filler 	*my_t;

	my_t = (t_filler*)malloc(sizeof(t_filler));
	make_structure(my_t);

	read_vm(my_t);
	close(g_fd);
	
	return (0);
}