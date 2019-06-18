#include<stdio.h>
int main()
{
    int a,b,c;
    while( scanf("%d%d%d",&a,&b,&c)&&a,b,c!=0)
    {
        if(c>a&&c>b)
        {
            if( c*c==a*a+b*b)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }

        }
        else if(a>b&&a>c)
        {
            if(a*a==b*b+c*c)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }
        }
        else
        {
            if(b*b==a*a+c*c)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
            }
        }
    }
   return 0;

}

