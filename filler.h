#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
#include <sys/stat.h> 
#include <fcntl.h>

int		g_fd;

typedef struct s_filler
{
	char		**tok;
	char 		**map;
	int 		sign;
	int 		map_row;
	int 		map_col;
	int 		tok_row;
	int 		tok_col;
	int			*tok_x;
	int			*tok_y;
	int			*valid_x;
	int			*valid_y;
	int			count;

}				t_filler;

void			reading_map(t_filler *my_t);
void			reading_token(t_filler *my_t);

#endif
