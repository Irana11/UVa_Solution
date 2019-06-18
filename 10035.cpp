#include<stdio.h>
#include<string.h>

int main()
{
    char s1[12],s2[12];
    int ar1[12],ar2[12],i,j,l1,l2,l,s,c;
    while(scanf("%s%s",s1,s2)==2)
    {
        if(strcmp(s1,"0")==0&&strcmp(s2,"0")==0)
        {
            break;
        }
        for(i=0;i<10;i++)
        {
            ar1[i]=0;
            ar2[i]=0;
        }
        c=0;
        s=0;
        l1=strlen(s1);
        l2=strlen(s2);
        for(i=l1-1,j=9;i>=0;i--,j--)
        {
            ar1[j]=s1[i]-48;
        }
         for(i=l2-1,j=9;i>=0;i--,j--)
        {
            ar2[j]=s2[i]-48;
        }
        s=0;
        for(i=9;i>=0;i--)
        {
            s=s+ar1[i]+ar2[i];
            if(s>9)
            {
                s=1;
                c++;
            }
            else
            {
                s=0;
            }
        }
        if(c==0)
        {
            printf("No carry operation.\n");
        }
        else if(c==1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n",c);
        }
    }
   return 0;
}
