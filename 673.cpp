#include<stdio.h>
#include<string.h>

int main()
{
    int l,t,i,j,f,flg;
    char ch[150];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(ch);
        l=strlen(ch);
        if(l==0)
        {
            printf("Yes\n");
            continue;
        }
        flg=0;
        for(i=0;i<l;i++)
        {
              if((ch[i]==')'||ch[i]==']')&&flg==0)
              {
                  j=i-1;
                  while(ch[j]==' ')
                  {
                      j--;
                  }
                  if((ch[j]=='('&&ch[i]==')')||(ch[j]=='['&&ch[i]==']'))
                  {
                      ch[i]=' ';
                      ch[j]=' ';
                  }
                  else
                  {
                      flg=1;
                  }
              }
        }
        f=0;
        for(i=0;i<l;i++)
        {
            if(ch[i]!=' ')
            {
                f=1;
            }
        }
        if(flg==0&&f==0)
        {
            printf("Yes\n");
        }
        else
        {
             printf("No\n");
        }
    }
    return 0;
}
