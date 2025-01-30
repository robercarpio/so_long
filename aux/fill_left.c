#include "aux.h"

int fill_left(char **map, int y, int x)
{
    while (x > 0 && map[y][x - 1] != '1')
    {
        if(map[y][x - 1] != 'E')
            return(1);
        map[y][x - 1] = 'V';
        x--;
    }
    return(0);
}

// void print_map(char **map, int rows)
// {
//     for (int i = 0; i < rows; i++)
//         printf("%s\n", map[i]);
// }

// int main(void)
// {
//     char *map[] = {
//         strdup("111111"),
//         strdup("101001"),
//         strdup("101101"),
//         strdup("100001"),
//         strdup("111111"),
//         NULL
//     };

//     printf("Before:\n");
//     print_map(map, 5);

//     fill_left(map, 3, 1);

//     printf("\nAfter:\n");
//     print_map(map, 5);

//     // Liberamos memoria
//     for (int i = 0; i < 5; i++)
//         free(map[i]);

//     return 0;
// }
