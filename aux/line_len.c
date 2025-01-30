#include "aux.h"

int	line_len(char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
