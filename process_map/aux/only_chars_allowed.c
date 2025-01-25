#include "aux.h"

#include <stdio.h>

int	only_chars_allowed(char *str, char *allow)
{
	int	i;
	int	b;

	while(*str)
	{
		b = 0;
		i = 0;
		while(allow[i] && b != 1)
		{
			if(*str == allow[i])
				b = 1;
			i++;
		}
		if (b == 0)
			return(0);
		str++;
	}
	return(b);
}
// int	main(void)
// {
// 	printf("%d\n",only_chars_allowed("01PC0\n","01PC\n"));
// 	return(0);
// }