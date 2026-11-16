/*
Le but de ce code est de calculer le temps que mets un balle a faire
un nombre de rebond jusqu'a s'arréter. Ce code affiche aussi le nombre d
rebond qu ela balle fait avant de s'arrêter

affiche ensuite le nombre de rebond :
durée totale                        :
hauteur max après le 1er rebond     :

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define G 9.81     // gravité (m/s^2)
#define DT 0.01    // pas de temps (s)
#define V_MIN 0.5  // vitesse de rebond minimale (m/s)
#define T_MAX 60.0 // durée maximale de simulation (s)

// Fait avancer la balle d'un pas de temps. Modifie la hauteur et la vitesse
// via les pointeurs.
void step(double *height, double *speed)
{
}

// Gère le rebond si la balle touche le sol. Retourne 1 s'il y a eu rebond, 0 sinon.
int bounce(double *height, double *speed, double restitution);

// Affiche une ligne du tableau de suivi.
void print_line(double time, double height, double speed, int bounces);

int main(int argc, char *argv[], double *height)
{
    double coef;
    if (argc < 2 || (sscanf(argv[1], "%lf", &height) != 1) || (sscanf(argv[2], "%lf", &coef)) != 1)
    {
        return 1;
    }
}
