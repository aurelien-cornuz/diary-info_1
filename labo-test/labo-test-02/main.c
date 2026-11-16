
#define WIDTH 60        // largeur du radar (m)
#define HEIGHT 20       // hauteur du radar (m)
#define DT 0.05         // pas de temps (s)
#define T_MAX 30.0      // durée maximale (s)
#define COLLISION_D 1.5 // distance de collision (m)
#define PI 3.14159265358979323846

typedef struct
{
    double x0, y0;    // position initiale (m)
    double speed;     // vitesse (m/s)
    double angle_deg; // angle (degrés)
    char symbol;      // symbole affiché sur le radar ('A' ou 'B')
} Drone;

// Conversion de degrés en radians
double deg_to_rad(double deg)
{
    Drone drone;

    deg = drone.angle_deg / 180.0;
}

// Position du drone à l'instant t, retournée via les pointeurs x et y
void position_at(const Drone *d, double t, double *x, double *y);

// Distance euclidienne entre deux points
double distance(double x1, double y1, double x2, double y2);

// Initialise toute la matrice avec le caractère '.'
void clear_radar(char radar[HEIGHT][WIDTH]);

// Marque la position (x, y) avec le symbole donné.
// Retourne 1 si la position est dans le radar, 0 sinon.
int plot(char radar[HEIGHT][WIDTH], double x, double y, char symbol);

// Affiche le radar (y = 0 en bas de l'écran)
void display(char radar[HEIGHT][WIDTH]);
