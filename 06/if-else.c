#include <stdio.h>


int main() {
    double note = 5.6;

    if ( note < 2.5 ) { 
        printf("Dommage, tu peux faire mieux la prochaine fois\n");
    } 
    else if ( note < 4.0 ) { 
        printf("Tu y es presque, la prochaine sera la bonne\n"); 
    } 
    else { 
        printf("Tu as la moyenne\n");
    }
}