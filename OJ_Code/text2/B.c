#include <stdio.h>

int main() {
    int a = 3,b = 4,c = 5;
    double x = 1.2, y = 2.4, z = -3.6;
    unsigned u = 51274,n = 128765;
    char c1 = 'a', c2 = 'b';
    printf("a= %d  b = %d  c= %d\n",a,b,c);
    printf("x=%lf, y=%lf, z=%lf\n",x,y,z);
    printf("x+y= %.2lf  y+z=%.2lf  z+x=%.2lf\n",x+y,y+z,z+x);
    printf("u= %i  n=%i\n",u,n);
    printf("c1=%c or %d(ASCII)\n",c1,c1);
    return 0;
}