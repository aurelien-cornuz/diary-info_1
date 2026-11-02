#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    srand(time(NULL));
    int random_number = rand() % N + 1;
    int compute = 0;
    int number = 0;
    scanf("%d", &number);
    printf("%d\n", number);
    printf("%d\n", random_number);

    do
    {
        printf("Vous avez choisi la valeur max : %d et le nombre rentré est : %d\n", N, number);

    }
    while(number != N){
        
    
        break;
    }

    
    return 0;
}
