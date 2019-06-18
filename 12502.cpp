#include<stdio.h>

int main()
{
    int t;
    double a,n,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&z);
        a=z/(x+y);
        n=a*x+(x-y)*a;
        printf("%.0lf\n",n);
    }

    return 0;
}
