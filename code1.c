#include <stdio.h>
int main()
{
 int d,f;
 float h,l,t,r;
 scanf("%f %f",&h,&l);
 t=(h/360)*l;
 d=t;
 r=t-d;
 r=r*60;
 d=d*6*6;
 d=d%12;
 if(r-d>0)
 d=r-d;
 else
 d=d-r;
 printf("%d",d);
    return 0;
}