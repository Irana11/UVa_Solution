#include<stdio.h>

int gcd(int a,int b)
{
    int tmp;
    while(b!=0)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
int main()
{
    int i,j,s,m,g;
    while((scanf("%d%d",&s,&m))==2)
    {
        g=gcd(s,m);

            printf("%10d%10d",s,m);

            if(g==1)
            {
                printf("    Good Choice\n");
            }
            else
            {
                printf("    Bad Choice\n");
            }
            printf("\n");



    }
    return 0;
}
