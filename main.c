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

int				root(int num)
{
	int			b;

	b = 1;
	while(b * b < num)
	{
		b++;
		if (b * b > num)
		{
			b--;
			break;
		}
	}
	return (b);
}

t_filler		search_for_sign(char *line)
{
	t_filler 	my_t;

	if (ft_strcmp(line, "$$$ exec p1 : [./akorol.filler]"))
	{
		my_t.sign = 'O';
		printf("1 1\n");
	}
	if (ft_strcmp(line, "$$$ exec p2 : [./akorol.filler]"))
	{
		my_t.sign = 'X';
		printf("2 2\n");
	}
	return (my_t);
}

void			read_vm()
{
	size_t		a;
	char		*line;
	char		*str;
	int			counter;
	t_filler	stuff;

	counter = 0;
	while ((a = get_next_line(1, &line)))
	{
		counter++;
		str = ft_strdup(line);
		if (counter == 7 || counter == 9)
			stuff = search_for_sign(str);
	}
	// size_t bytes;
	// char	buf[50];
	// while((bytes = read(1, buf, 50)))
	// {
	// 	printf("%c", buf[2]);
	// }
}

int main()
{
	read_vm();
	return (0);
}