#include "../so_long.h"
#include "../gnl/get_next_line.h"
#include "./libft/libft.h"


typedef struct {
	char 	**map;
	int		length;
	int		height;
} Map;

t_list *load_map()
{
	int fd = open("map", O_RDONLY);
	t_list	*map;
	t_list	*node_placer;
	char	*line;
	int		i;
	node_placer = ft_lstnew(NULL);
	map = node_placer;
	i = 0;
	do {
		line = get_next_line(fd);
		printf("%s",line);
		node_placer->content = ft_strdup(line);
		node_placer->next = ft_lstnew(NULL);
		node_placer = node_placer->next;
		free(line);
		i++;
	}
	while(line);
	return (map);
}

