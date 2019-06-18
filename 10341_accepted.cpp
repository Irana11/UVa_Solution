#include<stdio.h>
#include<math.h>
#define error 0.0000001

double a,b,x,low,high,mid,p,q,r,s,t,u;

double f(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
    {
        a=f(0);
        b=f(1);
        if(a*b>0)
           printf("No solution\n");
        else
        {
            low=0;
            high=1;
            while(low+error<high)
            {
                mid=(low+high)/2.00;
                if(f(mid)*f(low)>0)
                    low=mid;
                else
                    high=mid;
            }
             printf("%.4lf\n",mid);
        }

    }
    return 0;
}
//Bisection methood

