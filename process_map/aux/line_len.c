#include "aux.h"

int	line_len(char *str)
{
	int	i;

	if (!str || *str == '\0') // Asegura que no sea nulo o vacío
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n') // Cuenta caracteres hasta '\n' o fin
		i++;
	return (i);
}