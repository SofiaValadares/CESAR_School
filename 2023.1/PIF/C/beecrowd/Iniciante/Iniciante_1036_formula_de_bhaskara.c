#include <stdio.h>
#include <math.h>
 
int main() {
    double a, b, c, r1, r2, del, raiz_del;

    scanf("%lf %lf %lf", &a, &b, &c);

del = (b*b) - (4*a*c);

    if(a != 0 && del >= 0){
       raiz_del = sqrt(del); 
       r1 = (-b + raiz_del)/(2*a);
       r2 = (-b - raiz_del)/(2*a);
       printf("R1 = %.5lf\n", r1);
       printf("R2 = %.5lf\n", r2);
    }
    else{
        printf("Impossivel calcular\n");
    }

    return 0;
}