
#include<stdio.h>
#include<string.h>
int ara[1000];
char st[10000005];

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
    int t,i,j,l,max,g,k,x,n;
    char *ch ;
    scanf("%d",&t);
    gets(st);
    for(k=1;k<=t;k++)
    {
        gets(st);
        ch=strtok(st," ");
        j=0;
        while(ch!=NULL)
        {
           // printf("%s\n", ch);
            l=strlen(ch);
            n=0;
            for(i=0;i<l;i++)
            {
                n=(n*10)+ch[i]-48;
            }
            ara[j]=n;
            j++;

            ch=strtok(NULL," ");
        }
        max=0;
        for(i=0;i<j;i++)
        {
            for(x=i+1;x<j;x++)
            {
                g=gcd(ara[i],ara[x]);
                if(g>max)
                {
                    max=g;
                }
            }
        }
        printf("%d\n",max);

    }
    return 0;
}
