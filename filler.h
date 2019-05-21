#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct s_filler
{
	int		*token;
	char 	*map;
	int 	sign;
	int 	map_x;
	int 	map_y;
	int 	token_x;
	int 	token_y;
	int 	*map_xy;		// array for the possible coordinates of where to put the token

}				t_filler;

#endif
