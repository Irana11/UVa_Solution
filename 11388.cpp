
#include<stdio.h>

int main()
{
    int t,i,g,l,a,b,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {

        scanf("%d%d",&g,&l);
        if(l%g==0)
        {
            printf("%d %d\n",g,l);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;

}
