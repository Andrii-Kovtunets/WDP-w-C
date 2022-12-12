#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Print

int main()
{
    double ax;
    double ay;
    double bx;
    double by;
    double cx;
    double cy;
    double dx;
    double dy;

    while(1)
    {
        printf("Enter a >");
        scanf("%lf %lf", &ax, &ay);
        printf("Enter b >");
        scanf("%lf %lf", &bx, &by);
        printf("Enter b >");
        scanf("%lf %lf", &cx, &cy);
        printf("Enter b >");
        scanf("%lf %lf", &dx, &dy);

#ifdef Print
        printf("a = (%.2lf, %.2lf) ", ax, ay);
        printf("b = (%.2lf, %.2lf) ", bx, by);
        printf("c = (%.2lf, %.2lf) ", cx, cy);
        printf("d = (%.2lf, %.2lf) ", dx, dy);
#endif

        double px = bx-ax;
        double py = by-ay;

        double pLength = sqrt(px*px + py*py);
        if(pLength == 0)
        {
            printf("Error. Length of vector can not be 0");
        }

        double qx = dx-cx;
        double qy = dy-cy;

        double qLength = sqrt(qx*qx + qy*qy);
        if(qLength == 0)
        {
            printf("Error. Length of vector can not be 0");
        }

        printf("Result: ");
        if(px*qx + py*qy == 0)
        {
            printf("Prostopadle");
        }
        else if(px*qx - py*qy == 0)
        {
            printf("Rownolegle");
        }
        else
        {
            printf("-");
        }
        printf("\n\n");
    }
}
