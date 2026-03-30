#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main() {
    // Радиусы орбит
    double r_mars = 228;
    double r_earth = 150;

    // Период обращения вокруг солнца
    double T_mars = 687;
    double T_earth = 365;

    // Угловая скорость вращения
    double w_mars = 2 * PI / T_mars;
    double w_earth = 2 * PI / T_earth;

    double x, y;

    for (int t = 0; t <= 1000; t += 15) {
        x = r_mars * cos(w_mars * t) - r_earth * cos(w_earth * t);
        y = r_mars * sin(w_mars * t) - r_earth * sin(w_earth * t);

        printf("t = %4d   x = %8.2lf   y = %8.2lf\n", t, x, y);
    }
    return 0;
}