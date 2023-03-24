#include <stdio.h>
#include <math.h>

struct valores{
    int r1;
    int x1;
    int y1;
    int r2;
    int x2;
    int y2;
};

int positivo(int a);

int main(void){
    int r1_, x1_, y1_, r2_, x2_, y2_;
    double dist;
    
    while((scanf("%d %d %d %d %d %d\n", &r1_, &x1_, &y1_, &r2_, &x2_, &y2_)) != EOF){
        positivo(x1_);
        positivo(y1_);
        positivo(x2_);

        struct valores circ ={r1_, x1_, y1_, r2_, x2_, y2_};

        dist = sqrt((double)(circ.x1 - circ.x2)*(circ.x1 - circ.x2) + (double)(circ.y1 - circ.y2)*(circ.y1 - circ.y2)) + circ.r2;

        if(circ.r1>= dist){
            printf("RICO\n");
        }
        else{
            printf("MORTO\n");
        }
        dist = 0;

        r1_ = 0;
        x1_ =0;
        y1_ = 0;
        r2_ = 0;
        x2_ = 0;
        y2_ = 0;
    }

}

int positivo(int a){
    if(a<0){
        a = -a;
    }
    return a;
}


