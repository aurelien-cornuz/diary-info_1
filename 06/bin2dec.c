#include <stdio.h>

#include <stdbool.h>
#include <string.h>

/* Ce programme permet de convertir un nombre binaire en décimal

*/

int main(int argc, char *argv[])
{

    if (argc < 2)
        return 1;

    char *number = argv[1];

    bool valid = strlen(number) > 0;

    for (int i = 0; i < strlen(number); i++)
    {
        char c = number[i];

        if (c != '0' && c != '1')
        {
            valid = false;
            break;
        }
    }
    if (valid)
    {
        printf("le nombre est bel bien binaire et contient que des 0 et 1\n");
    }
    else
    {
        printf("Le nombre n'est pas binaire\n");
        return 1;
    }

    int result = 0;

    for (int i = 0; i < strlen(number); i++)
    {
        char bit = number[i] - '0';
        //printf("%hhd\n", bit);
        result = result * 2 + bit;
    }
    printf("%d\n", result);

    return 0;
}