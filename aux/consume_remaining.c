#include "aux.h"

void consume_remaining(int fd, int *is_rect)
{
    char *line;

    while ((line = get_next_line(fd)))
    {
        if (line[0] != '\0')
            *is_rect = 0;
        free(line);
    }
}