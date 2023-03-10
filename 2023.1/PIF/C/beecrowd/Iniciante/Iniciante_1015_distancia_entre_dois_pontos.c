#include <stdio.h>
#include <math.h>
 
int main() {
    float x1, x2, y1, y2, y, z, distancia;

    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
    
    z = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    distancia = sqrt(z);

    printf("%.4f\n", distancia);

    return 0;
}