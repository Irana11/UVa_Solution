#include<stdio.h>
#include<string.h>
#define sz 100005
char ch[sz],st[10000004];


int main()
{
    int i,j,x,y,l;
    char tmp;
    while(gets(st))
    {

        l=strlen(st);
        i=0;
        while(i<l)
        {
            for(x=0;x<sz;x++)
            {
                ch[x]=0;
            }

            j=0;
            while(st[i]!=32&&i<l)
            {
                ch[j]=st[i];
                j++;
                i++;
            }
            for(y=j-1,x=0;x<(j/2);y--,x++)
            {
               tmp=ch[y];
               ch[y]=ch[x];
               ch[x]=tmp;
            }

            printf("%s",ch);
            if(st[i]==32)
            {
                printf(" ");
                i++;
            }

        }
        printf("\n");
    }
    return 0;
}
