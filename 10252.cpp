#include<stdio.h>
#include<string.h>
#define sz 10005

int main()
{
    char s1[sz],s2[sz];
    int c1[130],c2[130],ar[130],i,j,l1,l2;
    while(gets(s1))
    {
        gets(s2);
        l1=strlen(s1);
        l2=strlen(s2);
        for(i=97;i<130;i++)
        {
            c1[i]=0;
            c2[i]=0;
            ar[i]=0;
        }
        for(i=0;i<l1;i++)
        {
            c1[s1[i]]++;
        }
          for(i=0;i<l2;i++)
        {
            c2[s2[i]]++;
        }
        for(i=97;i<123;i++)
        {
            if(c1[i]<c2[i])
                ar[i]=c1[i];
            else
                ar[i]=c2[i];
        }
        for(i=97;i<123;i++)
        {
            for(j=1;j<=ar[i];j++)
            {
                printf("%c",i);
            }
        }
        printf("\n");
    }
    return 0;
}
