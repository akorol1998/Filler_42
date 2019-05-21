#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 1

int				get_next_line(const int fd, char **line);

typedef struct	s_node
{
	int				content_fd;
	char			*content;
	struct s_node	*next;
	struct s_node	*start;
}				t_node;

#endif
