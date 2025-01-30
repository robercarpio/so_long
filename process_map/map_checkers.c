#include "process_map.h"

int is_rectangle(char *route)
{
    int fd;
    int len;
    int rows;
    int is_rect;
    char *line;
    int current_len;

    len = -1;
    rows = 0;
    is_rect = 1;
    if ((fd = open(route, O_RDONLY)) == -1)
        return (perror("Error al abrir el archivo"), -1);
    while ((line = get_next_line(fd)))
    {
        current_len = line_len(line);
        if (line[0] == '\0' || (len != -1 && current_len != len))
            return (free(line), close(fd), 0);
        if (len == -1)
            len = current_len;
        free(line);
        rows++;
    }
    consume_remaining(fd, &is_rect);
    close(fd);
    return (rows > 0 && is_rect);
}

int	check_borders_map(char *route)
{
	return(borders_h_checker(route) && borders_v_checker(route));
}

int	check_chars_allow(char *route)
{
	int	fd;
	char	*line;
	int	b;

	b = 1;
	if((fd = open(route,O_RDONLY))==-1)
		return(perror("Error al abrir el archivo"),-1);
	while((line = get_next_line(fd))!=NULL)
	{
		if(only_chars_allowed(line,"01CPE") == 0)
			return(0);
		free(line);
	}
	return(b);
}
int	main(void)
{
	printf("%d\n",check_chars_allow("/home/rcarpio-/Desktop/so_long/maps/map1.ber"));
	return(0);
}
