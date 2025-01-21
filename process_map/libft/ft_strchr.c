/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:21:12 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/26 18:59:10 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				b;
	unsigned char	ch;

	ch = c;
	b = 0;
	while (*s && b != 1)
	{
		if (*s != ch)
			s++;
		else
			b = 1;
	}
	if (!*s && ch != '\0')
		return (0);
	return ((char *)s);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    // Casos de prueba
    const char *test_strings[] = {
        "Hello, World!",
        "Test string",
        "Another test",
        "Special chars: *&^%$#@",
        "",                // Cadena vacía
        "abcabcabc",
        "abcdef\0hidden",  // Cadena con terminador nulo
    };

    int test_chars[] = {'H', 'o', '!', '*', '\0', 'x'};
    int num_strings = sizeof(test_strings) / sizeof(test_strings[0]);
    int num_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    // Prueba cada combinación de string y carácter
    for (int i = 0; i < num_strings; i++)
    {
        for (int j = 0; j < num_chars; j++)
        {
            const char *str = test_strings[i];
            int chr = test_chars[j];

            // Función original
            char *original = strchr(str, chr);

            // Función personalizada
            char *custom = ft_strchr(str, chr);

            printf("String: \"%s\", Character: '%c' (%d)\n", str, chr, chr);
            printf("Original strchr: %s\n", original ? original : "NULL");
            printf("Custom ft_strchr: %s\n", custom ? custom : "NULL");
            printf("\n");
        }
    }

    return 0;
}*/
