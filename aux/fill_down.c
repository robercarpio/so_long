#include "aux.h"

int	fill_down(char **map, int y, int x)
{
    int height = map_height(map);
    while (y < height - 1 && map[y + 1][x] != '1')
    {
        if(map[y + 1][x] != 'E')
            return(1);
        map[y + 1][x] = 'V';
        y++;
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

//     fill_down(map, 2, 1);

//     printf("\nAfter:\n");
//     print_map(map, 5);

//     // Liberamos memoria
//     for (int i = 0; i < 5; i++)
//         free(map[i]);

//     return 0;
// }