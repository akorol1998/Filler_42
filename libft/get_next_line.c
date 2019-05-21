#include "get_next_line.h"

void	create_new_node(int fd, t_node **list)
{
	t_node	*new;

	if (*list == NULL)
	{
		*list = (t_node *)malloc(sizeof(t_node));
		(*list)->content_fd = fd;
		(*list)->next = NULL;
		(*list)->start = *list;
		(*list)->content = ft_strnew(0);
	}
	else
	{
		new = (t_node *)malloc(sizeof(t_node));
		new->next = NULL;
		new->content = ft_strnew(0);
		new->start = (*list)->start;
		new->content_fd = fd;
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = new;
		*list = new;
	}
}

void	find_node(int fd, t_node **list)
{
	t_node	*rem;

	rem = *list;
	while (rem != NULL)
	{
		if (rem->content_fd == fd)
			break ;
		rem = rem->next;
	}
	if (rem == NULL)
		create_new_node(fd, list);
	else
		*list = rem;
}

int		ft_cut(t_node **list, char **line, int size, int counter)
{
	char	*rem;
	int		i;

	size = ft_strlen((*list)->content);
	while (((*list)->content)[counter] != '\n'
		&& ((*list)->content)[counter] != '\0')
		counter++;
	if (!(*line = (char *)malloc(sizeof(char) * (counter + 1))))
		return (-1);
	(*line)[counter] = '\0';
	i = -1;
	while (++i < counter)
		(*line)[i] = ((*list)->content)[i];
	if (((*list)->content)[counter] == '\n')
	{
		rem = ft_strsub((*list)->content, counter + 1, size);
		free((*list)->content);
		(*list)->content = rem;
		*list = (*list)->start;
	}
	else
		(*list)->content += counter;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_node	*list = NULL;
	char			*rem;

	if (line == NULL || fd < 0 || fd > 10240
		|| read(fd, NULL, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (list == NULL)
		create_new_node(fd, &list);
	else
		find_node(fd, &list);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		rem = list->content;
		list->content = ft_strjoin(list->content, buf);
		free(rem);
		if (ft_strchr(list->content, '\n') != NULL)
			return (ft_cut(&list, line, 0, 0));
	}
	if (ft_strchr(list->content, '\n') != NULL || (list->content)[0] != '\0')
		return (ft_cut(&list, line, 0, 0));
	return (0);
}
