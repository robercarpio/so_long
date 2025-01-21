/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:33:20 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/26 21:13:23 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	size_t	r_len;

	r_len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	ptr = malloc(r_len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int main()
{
    // Caso 1: Cadenas normales
    char *str1 = "Hola, ";
    char *str2 = "mundo!";
    char *resultado = ft_strjoin(str1, str2);
    if (resultado)
    {
        printf("Caso 1 - Resultado: %s\n", resultado);
        free(resultado);
    }

    // Caso 2: Primera cadena vacía
    char *str3 = "";
    char *str4 = "solo segundo string";
    resultado = ft_strjoin(str3, str4);
    if (resultado)
    {
        printf("Caso 2 - Resultado: %s\n", resultado);
        free(resultado);
    }

    // Caso 3: Segunda cadena vacía
    char *str5 = "solo primer string";
    char *str6 = "";
    resultado = ft_strjoin(str5, str6);
    if (resultado)
    {
        printf("Caso 3 - Resultado: %s\n", resultado);
        free(resultado);
    }

    // Caso 4: Ambas cadenas vacías
    char *str7 = "";
    char *str8 = "";
    resultado = ft_strjoin(str7, str8);
    if (resultado)
    {
        printf("Caso 4 - Resultado: \"%s\"\n", resultado);
        free(resultado);
    }

    // Caso 5: Cadenas largas
    char *str9 = "Esta es una cadena muy larga. ";
    char *str10 = "Esta es otra cadena muy larga.";
    resultado = ft_strjoin(str9, str10);
    if (resultado)
    {
        printf("Caso 5 - Resultado: %s\n", resultado);
        free(resultado);
    }

    return 0;
}*/
