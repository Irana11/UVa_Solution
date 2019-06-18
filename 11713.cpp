#include<stdio.h>
#include<string.h>
int a[200];
char s1[25],s2[25];

int main()
{
    int n,t,i,flg,l1,l2;
    a['a']=1;
    a['e']=1;
    a['i']=1;
    a['o']=1;
    a['u']=1;
    scanf("%d",&n);
   // getchar();
    for(t=1;t<=n;t++)
    {
        flg=0;

        scanf("%s%s",s1,s2);

        l1=strlen(s1);
        l2=strlen(s2);

        if(l1==l2)
        {
            i=0;
            while(i<l1)
            {
                 if(s1[i]==s2[i])
                 {
                     i++;
                 }
                 else if(a[s1[i]]==1&&a[s2[i]]==1)
                 {
                     i++;
                 }
                 else
                 {
                     flg=1;
                     break;
                 }
            }

        }
        else
        {
            flg=1;
        }
        if(flg==0)
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

