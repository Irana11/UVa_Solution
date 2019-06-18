#include<stdio.h>

int main()
{
    int i,H,D,F;
    double total,p,U;
    while(((scanf("%d%lf%d%d",&H,&U,&D,&F))==4)&&H!=0)
    {
        i=1;
        total=0;
        p=(U*F)/100.0;

        while(1)
        {
            if(U>0)
            {
                total+= U;
			}
            U -= p;

            if(total>H)
            {
                printf("success on day %d\n",i);
                break;
            }
             total=total-D;
             if(total<0)
            {
                 printf("failure on day %d\n",i);

                break;
            }

            i++;
        }

    }
    return 0;
}
