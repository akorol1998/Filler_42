/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:29:01 by akorol            #+#    #+#             */
/*   Updated: 2019/04/18 14:29:02 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft1/ft_printf.h"
#include "filler.h"

int		main()
{
	size_t		s;
	char		buf[BUF_SIZE];
	char		*line;
	int			a;

	a = 0;

	while (a < 10)
	{
		get_next_line(1, &line);
		a++;
		ft_printf("%s", line);
	}
	ft_printf("%s", "Can't hold it in");
	return (0);
}